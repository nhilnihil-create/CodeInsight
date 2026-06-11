#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
using ll = long long;
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using pll = pair<long long,long long>;
#define cY cout<<"Yes"<<endl
#define cN cout<<"No"<<endl
const long long INF = 1LL << 60;
const long long MOD = 1000000007;

//最大最小の入れ替え
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

//約数列挙
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}
//以上テンプレ
ll nCr(ll n, ll r) {
    ll ans = 1;
    for (int i = n; i > n - r; --i) {
        ans = ans*i;
    }
    for (int i = 1 ; i < r + 1; ++i) {
        ans = ans / i;
    }
    return ans;
}


int main(){
    ll N,K,S;
    cin>>N>>K>>S;
    rep(i,K){
        cout<<S;
        if(i==N-1){
            cout<<endl;
        }else{
            cout<<" ";
        }
    }
    rep(i,N-K){
        if(S!=1000000000){
            cout<<S+1;
        }else{
            cout<<1;
        }
        if(i==N-K-1){
            cout<<endl;
        }else{
            cout<<' ';
        }
    }
    }
