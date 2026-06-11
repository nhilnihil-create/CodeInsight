#include <iostream>
#include <vector>
using namespace std;

vector<int> g[100005];
int n, m, h[100005], ans;

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> h[i];
    while(m--) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) {
        bool good = true;
        for(auto next: g[i])
            if(h[next] >= h[i])
                good = false;
        if(good) ans++;
    }
    cout << ans;
}
