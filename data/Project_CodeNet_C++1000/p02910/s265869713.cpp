#include <bits/stdc++.h>

using namespace std;
#define DBG(x)                         \
    (void)(cout << "L" << __LINE__     \
                << ": " << #x << " = " \
                << (x) << '\n')
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
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
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (i % 2)
        {
            if (s[i] == 'L' || s[i] == 'U' || s[i] == 'D')
            {
                continue;
            }
            else
            {
                cout << "No\n";
                return 0;
            }
        }
        else
        {
            if (s[i] == 'R' || s[i] == 'U' || s[i] == 'D')
            {
                continue;
            }
            else
            {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
    return 0;
}