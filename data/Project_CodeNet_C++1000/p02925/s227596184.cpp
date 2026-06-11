#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repn(i,n) for(int i = 0; i <= (int)(n); i++)
#define srep(i,l,n) for(int i = l; i < (int)(n); i++)
#define srepn(i,l,n) for(int i = l; i <= (int)(n); i++)
#define drep(i,n) for(int i = (int)(n-1); i >= 0; i--)
#define drepn(i,n) for(int i = (int)(n); i >= 0; i--)
#define size(s) (int)s.size()
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
bool isIn(int i, int j, int h, int w) {return i >= 0 && i < h && j >= 0 && j < w;}
void Yes(){cout << "Yes" << endl;}
void No(){cout << "No" << endl;}
void YES(){cout << "YES" << endl;}
void NO(){cout << "NO" << endl;}
void err() {cout << -1 << endl;}
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define ep emplace_back

const int MOD = 1000000007;
const int INF = 1e9;

#define PI acos(-1);
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};

int n;
vector<vector<int>> a;
vector<vector<int>> id;
const int mxN = 1003;
const int mxV = mxN*(mxN-1)/2;
int dp[mxV];
vector<int> to[mxV];
bool calculated[mxV] = {false};
bool seen[mxV] = {false};

int dfs(int i) {
    if(seen[i]) {
        if(!calculated[i]) return -1;
        return dp[i];
    }
    seen[i] = true;
    dp[i] = 1;
    for(auto v : to[i]) {
        int res = dfs(v);
        if(res == -1) return -1;
        chmax(dp[i], res + 1);
    }
    calculated[i] = true;
    return dp[i];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    a.assign(n, vector<int>(n-1));
    id.assign(n, vector<int>(n));
    rep(i, n) {
        rep(j, n-1) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    int V = 0;
    rep(i, n) rep(j, n) {
        if(i < j) id[i][j] = V++;
    }
    auto getId = [&](int i, int j) {
        if(i > j) swap(i, j);
        return id[i][j];
    };
    rep(i, n) {
        rep(j, n-1) {
            a[i][j] = getId(i, a[i][j]);
        }
    }
    rep(i, n) {
        rep(j, n-2) {
            to[a[i][j+1]].push_back(a[i][j]);
        }
    }
    int ans = 0;
    rep(i, V) {
        int res = dfs(i);
        if(res == -1) {
            puts("-1");
            return 0;
        }
        chmax(ans, res);
    }
    cout << ans << endl;

}