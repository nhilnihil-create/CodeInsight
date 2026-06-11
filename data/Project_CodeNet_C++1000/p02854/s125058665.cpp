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
    int n;
    cin >> n;
    vector<ll> v(n);
    rep(i,n) cin >> v[i];
    vector<ll> sum(n+1,0);
    rep(i,n) sum[i+1] = sum[i] + v[i];
    ll ans = INF;
    rep(i,n){
        ans = min(ans, abs((sum[n]-sum[i]) - sum[i]));
    }
    cout << ans << endl;
    return 0;
}