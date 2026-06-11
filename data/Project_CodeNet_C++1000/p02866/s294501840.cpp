#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

const ll MOD = 998244353;

ll modpow(ll n, ll p, ll m) {
    ll res = 1;
    while(p>0){
        if(p%2==1) res = (res * n) % m;
        n = (n * n) % m;
        p /= 2;
    }
    return res;
}

int cnt[101010];
int v[101010];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    int mx_dist = 0;
    rep(i,n) {
        int t;cin>>t;
        v[i] = t;
    }
    rep(i,n){
        cnt[v[i]]++; 
    }
    rep(i,n){
        mx_dist = max(mx_dist, v[i]);
    }
    if(v[0] != 0 || cnt[0]!=1){
        cout<<'0'<<endl;
        return 0;
    }
    ll ans = 1;
    for(int i=1; i<=mx_dist; i++){
        // ans *= modpow((ll)cnt[i-1], (ll)cnt[i], MOD)%MOD;
        for(int j=0; j<cnt[i]; j++) ans = ans * cnt[i-1] % MOD;
    }
    cout<<ans%MOD<<endl;
}