#include <bits/stdc++.h>

using namespace std;
#define DBG(x)                         \
    (void)(cout << "L" << __LINE__     \
                << ": " << #x << " = " \
                << (x) << '\n')
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 110000;
int main()
{
    //检查有没有特判0,有没有越界限.
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(12);
    string s, t;
    cin >> s >> t;
    int a, b;
    cin >> a >> b;
    string u;
    cin >> u;
    if (u == s)
        a--;
    else if (u == t)
        b--;
    cout << a << " " << b << "\n";
    return 0;
}