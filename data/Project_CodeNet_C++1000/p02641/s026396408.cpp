#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define dbg(x) cout << #x << ": " << x << endl;
using namespace std;

map<int, bool> vis;
int a[10010];

int main()
{
    int x, n;
    cin >> x >> n;
    rep(i, 1, n) {
        cin >> a[i];
        vis[a[i]] = true;
    }
    int delta = 0;
    while (true) {
        if (!vis[x - delta]) {
            cout << x - delta << endl;
            return 0;
        }
        if (!vis[x + delta]) {
            cout << x + delta << endl;
            return 0;
        }
        delta++;
    }

}
