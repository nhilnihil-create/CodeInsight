#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
using namespace std;
using ll = long long;
constexpr int mod = 1e9 + 7;

int main()
{
    int n, k, r, s, p, ans = 0;
    bool pre = true;
    cin >> n >> k >> r >> s >> p;
    string t;
    cin >> t;
    for (size_t i = 0; i < k; i++)
    {
        for (size_t j = i; j < t.size(); j += k)
        {
            if (j != i && t[j] == t[j - k] && pre)
            {
                pre = !pre;
                continue;
            }

            if (t[j] == 'r')
            {
                ans += p;
            }
            else if (t[j] == 's')
            {
                ans += r;
            }
            else
            {
                ans += s;
            }
            pre = true;
        }
    }
    cout << ans << endl;
    return 0;
}
