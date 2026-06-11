#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    ll n,k;
    cin >> n >> k;
    vector<int> v(n);
    rep(i,n) cin >> v[i];
    ll right = 0;
    ll all = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1 ;j < n; j ++){
            if(v[i] > v[j]) right++;
        }
        for(int j = 0; j < n ; j ++){
            if(v[i] > v[j]) all++;
        }
        /*
        ans += right * k % MOD;
        ans += k*(k-1)/2 %MOD * all % MOD;
        ans %= MOD;*/
    }
    ans += right * k % MOD;
    ans += k*(k-1)/2 %MOD * all % MOD;
    ans %= MOD;
    cout << ans << endl;
    return 0;
}