#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;
#define DBG(x)                         \
    (void)(cout << "L" << __LINE__     \
                << ": " << #x << " = " \
                << (x) << '\n')
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 110000;
int x[maxn];
void run_case()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    int ans = INF;
    for (int pos = 1; pos <= 100; pos++)
    {
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            res += (x[i] - pos) * (x[i] - pos);
        }
        ans = min(res, ans);
    }
    cout << ans << "\n";
}
int main()
{
    //检查有没有特判0,有没有越界限.
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(12);
    run_case();
    return 0;
}