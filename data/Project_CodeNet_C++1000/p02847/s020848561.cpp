#include <bits/stdc++.h>

using namespace std;
#define DBG(x)                         \
    (void)(cout << "L" << __LINE__     \
                << ": " << #x << " = " \
                << (x) << '\n')

typedef long long ll;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int maxn = 110000;
int main()
{
    //检查有没有特判0,有没有越界限.
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(12);
    string s;
    cin >> s;
    if (s == "SUN")
        cout << 7 << "\n";
    else if (s == "MON")
        cout << 6 << "\n";
    else if (s == "TUE")
        cout << 5 << "\n";
    else if (s == "WED")
        cout << 4 << "\n";
    else if (s == "THU")
        cout << 3 << "\n";
    else if (s == "FRI")
        cout << 2 << "\n";
    else if (s == "SAT")
        cout << 1 << "\n";
    return 0;
}