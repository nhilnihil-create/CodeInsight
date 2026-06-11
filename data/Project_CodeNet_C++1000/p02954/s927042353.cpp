#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

string S;

int dfs(string &S, vector<int> &seen, int i) {
    int res = 0;
    if (seen[i]!=0) return seen[i];
    else if (S[i]=='R' && S[i+1]=='L') {
        seen[i] = 1;
        return 1;    
    }
    else if (S[i]=='L' && S[i-1]=='R') {
        seen[i] = 1;
        return 1;
    }
    else {
        if (S[i]=='R') {
            res = dfs(S,seen,i+1) + 1;
            seen[i] = res;
        }
        else {
            res = dfs(S,seen,i-1) + 1;
            seen[i] = res;
        }
        return res;
    }
}

int main(){
    cin >> S;
    vector<int> seen(S.size(),0);
    int N = seen.size();
    int ans[N] = {};
    rep(i,N) {
        seen[i] = dfs(S,seen,i);
        if (S[i]=='R' && seen[i]%2==0) ans[i+seen[i]]++;
        else if (S[i]=='R' && seen[i]%2!=0) ans[i+seen[i]-1]++;
        else if (S[i]=='L' && seen[i]%2==0) ans[i-seen[i]]++;
        else ans[i-seen[i]+1]++;
    }
    rep(i,N) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
