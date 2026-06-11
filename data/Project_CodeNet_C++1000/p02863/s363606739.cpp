#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<string>> vvs;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define vrep(v,n) for(int i=0;i<n;i++){cin >> v.at(i);} 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, n) for (int i = 0; i <= (int)(n); i++)
#define srep(i, l, n) for (int i = l; i < (int)(n); i++)
#define srepn(i, l, n) for (int i = l; i <= (int)(n); i++)
#define pb push_back 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int mod = 1000000007;
const int inf = 1e9;
#define PI 3.14159265369;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};


int main(){
    int n, t;
    cin >> n >> t;
    vector<P> p(n);
    rep(i,n) cin >> p[i].first >> p[i].second;
    int dp[n+1][t+1];
    repn(i,n) fill(dp[i], dp[i]+t+1, 0);
    sort(p.begin(), p.end());
    int ans = 0;
    rep(i,n){
        rep(j,t){ 
            chmax(dp[i+1][j], dp[i][j]);
            int nj = j + p[i].first;
            if(nj < t) chmax(dp[i+1][nj], dp[i][j]+p[i].second);
        }
        int now = dp[i][t-1] + p[i].second;
        chmax(ans, now);
    }
    cout << ans << endl;
}