#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int dfs(vector<vector<int>> &A, vector<int> &seen, int i) {
    seen[i] = 1;
    int res = 1;
    rep(j,A[i].size()) {
        int to = A[i][j];
        if (seen[to]!=-1) continue;
        res += dfs(A,seen,to);
    }
    return res;
}

int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<int>> A(N,vector<int>(0));

    rep(i,M) {
        int a,b;
        cin >> a >> b;
        a--,b--;
        A[a].push_back(b);
        A[b].push_back(a);
    }
    
    vector<int> seen(N,-1);

    int ans = 0;
    rep(i,N) {
        if (seen[i]!=-1) {
            continue;
        }
        //cout << dfs(A,seen,i) << endl;
        ans = max(ans,dfs(A,seen,i));
        //cout << ans << endl;
    }
    cout << ans << endl;
}
