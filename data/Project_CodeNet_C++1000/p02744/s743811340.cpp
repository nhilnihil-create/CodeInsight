#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

int n;
void dfs(char maxc, string ans){
    if(ans.size() == n) {
        cout << ans << endl;
        return;
    }
    for(char c = 'a'; c <= maxc; c++){
        if(c == maxc) dfs(maxc + 1, ans + c);
        else dfs(maxc, ans + c);
    }
}

signed main() {
    cin >> n;

    dfs('a', "");
}