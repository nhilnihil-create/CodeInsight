#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int x;
    cin >> x;
    int a = x % 100;
    int b = x / 100;
    int c = 0;
    if(a % 5 == 0) c = a / 5;
    else c = a / 5 + 1;
    if(b >= c) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}