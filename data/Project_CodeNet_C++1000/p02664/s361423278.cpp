#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string t; cin >> t;
    for (auto &c: t) {
        if (c == '?') c = 'D';
    }
    cout << t << endl;
    return 0;
}