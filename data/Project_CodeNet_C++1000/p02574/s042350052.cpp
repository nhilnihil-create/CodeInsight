#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
const long long INF = 1LL << 60;
const int MOD = 1e9 + 7;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


/* ACL */

//using namespace atcoder;

//MAXR=10^5であることに注意
#define PN 1 //素数のマークは1
#define MAXR 1000000

vector<ll> PN_chk(MAXR+1,PN);//0-indexed(0~MAXR)

//素因数分解で出てきた素数を全て挿入する
vector<ll> prime;

vector<bool> isAlready(MAXR+1,false);

//O(MAXR)
void init_eratosthenes(){
    ll MAXRR=sqrt(MAXR)+1;
    //2以上の数の素因数分解をするので無視して良い
    PN_chk[0]=0;PN_chk[1]=0;
    rep2(i,2,MAXRR){
        //たどり着いた時に素数と仮定されているなら素数
        //ある素数の倍数はその素数で割り切れるのでマークづけ
        if(PN_chk[i]==1) rep2(j,i,ll(MAXR/i)){PN_chk[j*i]=i;}
    }
}

//O(logn)
//primeは整列されていない
bool prime_factorize(ll n){
    if(n<=1) return true;
    //1の場合はnは素数
    if(PN_chk[n]==1){
        //prime.push_back(n);
        //return true;
        PN_chk[n] = n;
    }
    //マークされている数は素数
    prime.push_back(PN_chk[n]);

    if(isAlready.at(PN_chk[n])){
        return false;
    }
    isAlready.at(PN_chk[n]) = true;

    ll next_n = n;
    while(next_n % PN_chk[n] == 0){
        next_n /= PN_chk[n];
    }
    //マークされている数でnを割った数を考える
    return prime_factorize(ll(next_n));
}


int main(){
    int N;
    cin >> N;

    vector<int> list_A(N);
    init_eratosthenes();

    rep(i,N){
        int a;
        cin >> a;
        list_A.at(i) = a;
    }

    int r = accumulate(list_A.begin(), list_A.end(), 0, [](int m, int n) {
        return gcd(m, n);
    });

    if(r != 1){
        cout << "not coprime" << endl;
        return 0;
    }

    bool isP = true;
    rep(i,N){
        isP &= prime_factorize(list_A.at(i));
    }

    if(isP){
        cout << "pairwise coprime" << endl;
    }else{
        cout << "setwise coprime" << endl;
    }
    
    return 0;
}