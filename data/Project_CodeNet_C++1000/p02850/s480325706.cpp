#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
using VB  = vector<bool>;
using VI  = vector<int>;
using PII = pair<int, int>;
using VP  = vector<PII>;
using VVP = vector<VP>;
VB viz;
VI color;
VVP g;
int n, cmax;
inline void DFS(int x, int w) {
    viz[x] = true;
    int temp(1), y, i;
    for (const PII& P : g[x]) {
        tie(y, i) = P;
        if (!viz[y]) {
            DFS(y, temp + (temp >= w));
            color[i] = temp + (temp >= w);
            ++temp;
        }
    }
}
int x, y;
int main() {
    DAU
    cin >> n;
    g = VVP(n + 1);
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        g[x].emplace_back(y, i);
        g[y].emplace_back(x, i);
    }
    viz = VB(n + 1);
    color = VI(n);
    DFS(1, n);
    for (int i = 1; i < n; ++i)
        cmax = max(cmax, color[i]);
    cout << cmax << '\n';
    for (int i = 1; i < n; ++i)
        cout << color[i] << '\n';
    PLEC
}
