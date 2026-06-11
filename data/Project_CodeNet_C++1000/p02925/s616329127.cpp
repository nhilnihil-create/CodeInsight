#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,s,n) for(int i=(s); i<(n); i++)
#define all(v) v.begin(),v.end()
#define outve(v) for(auto i : v) cout << i << " ";cout << endl
#define outmat(v) for(auto i : v){for(auto j : i) cout << j << " ";cout << endl;}
#define in(n,v) for(int i=0; i<(n); i++){cin >> v[i];}
#define out(n) cout << (n) << endl
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
#define infi 1900000000
#define infl 1100000000000000000
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
#define csp << " " <<
#define outset(n) cout << fixed << setprecision(n);
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> using ve = vector<T>;
template<typename T> using pq2 = priority_queue<T>;
template<typename T> using pq1 = priority_queue<T,vector<T>,greater<T>>;


const int max_N = 1005;
const int max_V = max_N*max_N;
vi to[max_V];
int id[max_N][max_N];

int toId(int i,int j){
    if(i > j) swap(i,j);
    return id[i][j];
}

bool visited[max_V];
bool calc[max_V];
int dp[max_V];

int dfs(int v){
    if(visited[v]){
        if(!calc[v]) return -1;
        return dp[v];
    }
    visited[v] = true;
    dp[v] = 1;
    
    for (int u : to[v]) {
        int res = dfs(u);
        if(res == -1) return -1;
        dp[v] = max(dp[v],dfs(u)+1);
    }
    calc[v] = true;
    return dp[v];
    
    
}



int main()
{
    int N;
    cin >> N;
    
    ve<vi> A(N,vi(N-1));
    rep(i,N) rep(j,N-1){ cin >> A[i][j];A[i][j]--;}
    int V = 0;
    rep(i,N) rep(j,N) {
        if(i<j) id[i][j] = V++;
    }
    rep(i,N){
        rep(j,N-1){
            A[i][j] = toId(i,A[i][j]);
        }
        rep(j,N-2){
            to[A[i][j+1]].pb(A[i][j]);
        }
    }
    
    int ans = 0;
    rep(i,V){
        int res = dfs(i);
        if(res == -1){
            cout << -1 << endl;
            return 0;
        }
        ans = max(ans,res);
    }
    
    
    out(ans);
    

    return 0;
}
