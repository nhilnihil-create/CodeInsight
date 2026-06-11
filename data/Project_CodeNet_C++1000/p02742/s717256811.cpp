#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    ll h, w;
    cin >> h >> w;
    if(h == 1 || w == 1) cout << 1 << endl;
    else if(h % 2 == 0) cout << h / 2 * w << endl;
    else if(w % 2 == 0) cout << w / 2 * h << endl;
    else cout << (h - 1) / 2 * w + w / 2 + 1 << endl;
    return 0;
}