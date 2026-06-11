#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define print(v) cout<<v<<endl;
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=998244353;

// a^n mod を計算する
//ただしmodとaが互いにその時のみ
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
    ll N;
    cin >> N;
    vector<ll> D(N,0);
    for(ll i=0;i<N;i++)cin>>D[i];
    if(D[0]!=0){
        print(0)return 0;
    }
    Map M;
    for(ll i=0;i<N;i++)M[D[i]]++;
    ll S=M.size();
    ll ans=1;
    if(M[0]!=1){print(0)return 0;}
    vector<ll> vec(S,0);
    for(ll i=1;i<S;i++){
        if(M[i]==0){
            cout<<0<<endl;return 0;
        }
        vec[i]=M[i];
    }
    vec[0]=1;
    for(ll i=1;i<S;i++){
        ans*=modpow(vec[i-1],vec[i],MOD);
        ans%=MOD;
    }
    print(ans);

    

    return 0;
}