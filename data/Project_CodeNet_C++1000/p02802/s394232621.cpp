#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

bool a[100005];
int p[100005];

int main() {
    int n, m;
    cin >> n >> m;

    int ac = 0, pena = 0;
    rep(i, m) {
        int x;
        string s;
        cin >> x >> s;
        if (a[x]) continue;

        if (s == "AC")
            a[x] = 1, ac++, pena += p[x];
        else
            p[x]++;
    }

    cout << ac << ' ' << pena << endl;
    return 0;
}
