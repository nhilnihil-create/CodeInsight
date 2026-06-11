#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    bool ok = false;
    repl(i, 1, n + 1) {
        int x = floor(i * 1.08);
        if(x == n) {
            cout << i << endl;
            ok = true;
            break;
        }
    }
    if(ok == false) cout << ":(" << endl;
    return 0;
}