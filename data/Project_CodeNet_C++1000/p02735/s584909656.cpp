#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(), a.end()
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
#define pb push_back
#define sz(x) (int)(x).size()
#define PQ(T) priority_queue<T, v(T), greater<T>>
#define bn(x) ((1 << x) - 1)
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int mod = 1000000007;

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    vvi dp(h, vi(w, 0));

    int ans=0;

    rep(i, h)rep(j, w){
        if(i==0&&j==0){
            if(s[0][0]=='#') ans++;
            continue;
        }
        int up = INF;
        int left = INF;
        if(i!=0){
            up = dp[i-1][j];
            if(s[i-1][j]=='.' && s[i][j]=='#') up+=1000;
            else up++;
        }
        if(j!=0){
            left = dp[i][j-1];
            if(s[i][j-1]=='.' && s[i][j]=='#') left+=1000;
            else left++;
        }
        dp[i][j] = min(up, left);
    }

    ans += dp[h-1][w-1]/1000;

    cout << ans << endl;

    return 0;
}