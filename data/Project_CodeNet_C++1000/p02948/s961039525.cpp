#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //int:2*10**9
typedef long double ld;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define REPS(i,n) for (ll i = 1; i<=(ll)(n); i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define vec2(name,i,j) vector<vector<ll>> name(i,vector<ll>(j))
#define vec2f(name,i,j,k) vector<vector<ll>> name(i,vector<ll>(j,k))
#define vec3(name,i,j,k) vector<vector<vector<ll>>> name(i,vector<vector<ll>>(j,vector<ll>(k)))
#define vec3f(name,i,j,k,l) vector<vector<vector<ll>>> name(i,vector<vector<ll>>(j,vector<ll>(k,l)))
#define vec4(name,i,j,k,l) vector<vector<vector<vector<ll>>>> name(i,vector<vector<vector<ll>>>(j,vector<vector<ll>>(k,vector<ll>(l))))
#define vec4f(name,i,j,k,l,m) vector<vector<vector<vector<ll>>>> name(i,vector<vector<vector<ll>>>(j,vector<vector<ll>>(k,vector<ll>(l,m))))
#define pb push_back
#define MOD 1000000007
#define MOD2 998244353
#define PI 3.141592653
#define INF 100000000000000 //14
#define N 101010
//cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);

int main(){
    ll n, m, x, y; cin >> n >> m;
    vector<vector<ll>> a(N);
    REP(i,n){
        cin >> x >> y;
        if (m-x>=0) a[m-x].pb(y);
    }
    priority_queue<ll, vector<ll>, less<ll>> q;
    ll ans = 0;
    FORD(i,m,0){
        REP(j,a[i].size())q.push(a[i][j]);
        if (q.size()) {
            ans+=q.top();
            q.pop();
        }
    }
    cout << ans << endl;
}