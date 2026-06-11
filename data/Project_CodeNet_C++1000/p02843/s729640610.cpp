#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int x;
    cin >> x;
    int d = x / 100;
    int l = d * 100 + d * 5;
    if (x <= l) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}