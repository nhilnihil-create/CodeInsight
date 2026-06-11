#include <iostream>
#include <cstdio>
using namespace std;
int n;
int ans[11];
bool vis[30];
void dfs(int x) {
    if (x == n) {
        for (int i = 1; i <= n; i++) {
            cout << (char)(ans[i] + 'a');
        }
        puts("");
        return;
    }
    for (int i = 0; i <= 26; i++) {
        if (vis[i]) {
            ans[x + 1] = i;
            dfs(x + 1);
        } else {
            vis[i] = 1;
            ans[x + 1] = i;
            dfs(x + 1);
            vis[i] = 0;
            break;
        }
        
    }
}
int main() {
    cin >> n;
    dfs(0);
    return 0;
}

