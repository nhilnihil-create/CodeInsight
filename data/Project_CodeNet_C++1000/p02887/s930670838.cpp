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
const long double PI = (acos(-1));
const long double EPS = 0.0000000001;
const int INF = 0x3f3f3f3f;
const int maxn = 110000;
int main()
{
    //检查有没有特判0,有没有越界限.
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(12);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int len = s.size();
    int cnt = 1;
    for (int i = 1; i < len; i++)
    {
        if (s[i] == s[i - 1])
            continue;
        cnt++;
    }
    cout << cnt << "\n";
    return 0;
}