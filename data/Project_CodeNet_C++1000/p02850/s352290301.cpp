#include <bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define INF INT_MAX // 2147483647
#define INFLL LLONG_MAX // 9223372036854775807
#define rep(i, n) for(lli i=0, i##_len=(lli)(n); i<i##_len; i++)
#define repf(i, n) for(lli i=1, i##_len=(lli)(n+1); i<i##_len; i++)
#define per(i, n) for(lli i=((lli)(n))-1; i>=0; i--)
#define perf(i, n) for(lli i=((lli)(n)); i>0; i--)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<lli>
#define vvi vector<vector<lli>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

// sv:始点ノード, pa:親, pac：親の色, g：グラフ, ans：答え格納用
void dfs(lli sv, lli pa, lli pac, vector<vector<pair<lli, lli>>> &g, vector<lli> &ans){
    lli c = 1;
    if(c == pac) c++;

    for(auto p: g[sv]){
        // 子から親の方向は考えない
        if(p.first == pa) continue;
        ans[p.second] = c;
        dfs(p.first, sv, c, g, ans);
        c++;
        if(c == pac) c++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);
    
    lli n;
    cin >> n;
    // グラフ（隣接ノード, エッジ番号）
    vector<vector<pair<lli, lli>>> g(n);
    for(lli i=0; i<n-1; i++){
        lli n1, n2;
        cin >> n1 >> n2;
        n1--; n2--; // 0-Origin
        g[n1].emplace_back(n2, i);
        g[n2].emplace_back(n1, i);
    }

    // 最大の次数を持つノード
    lli maxc = 0;
    for(lli i=0; i<n; i++) chmax(maxc, (lli)g[i].size());

    // 0番のノードを始点にDFS
    vector<lli> ans(n-1, -1);
    dfs(0, -1, -1, g, ans);

    // 答えの出力
    cout << maxc << endl;
    for(auto p: ans) cout << p << endl;
}