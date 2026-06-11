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
const int maxn = 1100000;

void run_case()
{
    ll x;
    cin >> x;
    vector<int> p;
    while (x)
    {
        int cur = x % 26;
        if (cur == 0)
        {
            p.push_back(26);

            x = x / 26 - 1;
        }
        else
        {
            p.push_back(cur);
            x /= 26;
        }
    }
    for (int i = p.size() - 1; i >= 0; i--)
    {
        cout << char(p[i] + 'a' - 1);
    }
    cout << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(12);
    run_case();
    cout.flush();
    return 0;
}