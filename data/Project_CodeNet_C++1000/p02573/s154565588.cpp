#include <vector>
#include <iostream>
using namespace std;

vector<int> g[200005];
int n, m, cc[200005], mx, number[200005], currComp;

void dfs(int x) {
    cc[x] = currComp;
    number[currComp]++;
    for(auto next: g[x])
        if(!cc[next])
            dfs(next);
}

int main() {
    cin >> n >> m;
    while(m--) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i = 1; i <= n; i++)
        if(!cc[i]) {
            currComp++;
            dfs(i);
            mx = max(mx, number[currComp]);
        }
    cout << mx;
}

