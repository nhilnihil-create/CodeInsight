#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define Rep(i,n) for(int i = 1; i <= n; i++)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
template<class T> using V = vector<T>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll mod = 1e9+7;

int main(){
    
    int n, m;
    cin >> n >> m;
    V<bool> broken(n+1);
    rep(i,m) {
        int a;
        cin >> a;
        broken[a] = true;
    }

    ll dp[100005] = {};
    dp[0] = !broken[0];
    dp[1] = !broken[1];
    for(int i = 2; i <= n; i++) {
        if(broken[i]) continue;
        dp[i] = (dp[i-1] + dp[i-2]) % mod;
    }
    cout << dp[n] << endl;
}