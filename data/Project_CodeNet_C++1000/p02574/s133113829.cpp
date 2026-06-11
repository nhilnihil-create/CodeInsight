#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001

#define MR 1000000
vector<ll> PN_chk(MR+1,1);

//O(MR)
void init_eratosthenes(){
    PN_chk[0]=0;PN_chk[1]=0;//2以上の数の素因数分解をするので無視して良い
    for(int i=2;i<=sqrt(MR)+1;i++){
        //たどり着いた時に素数と仮定されているなら素数
        //ある素数の倍数はその素数で割り切れるのでマークづけ
        if(PN_chk[i]==1) {
            for(int j=2;j<=MR/i;j++){
                PN_chk[j*i]=i;
            }
        }
    }
}

//素因数分解で出てきた素数を全て挿入する
vector<ll> prime;

//O(logn)
//primeは整列されていない
void prime_factorize(ll n){
    if(n<=1) return;
    //1の場合はnは素数
    if(PN_chk[n]==1){
        prime.push_back(n);
        return;
    }
    //マークされている数は素数
    prime.push_back(PN_chk[n]);

    //マークされている数でnを割った数を考える
    prime_factorize(ll(n/PN_chk[n]));
}//mainでinitを一度実行、primeはnの度に初期化

ll gcd(ll a, ll b){
    if (a%b == 0) return(b);
    else return(gcd(b, a%b));
}
 
ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}

int main() {
    init_eratosthenes();

    int n;cin >> n;
    vector<int> s(1000001);
    bool pairwise=true;
    vector<ll> a(n);for(int i=0;i<n;i++) cin >> a[i];

    for(int i = 0; i < n; i++) {
        prime_factorize(a[i]);
        for(int j = 0; j < prime.size(); j++) {
            if(s[prime[j]]==0) s[prime[j]]=i;
            else if(s[prime[j]]!=i){
                pairwise=false;
            }
        }
        vector<ll> x;
        prime=x;
    }

        if(pairwise==true){
            cout << "pairwise coprime" << endl;
            return 0;
        }
        else{
            ll p=a[0];
            for(int i = 1; i < n; i++) {
                p = gcd(p,a[i]);
            }

            if(p==1){
                cout << "setwise coprime" << endl;
            }
            else{
                cout << "not coprime" << endl;
            }
        }
    
    
    return 0;
}