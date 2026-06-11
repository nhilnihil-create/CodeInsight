#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <cmath>
using namespace std;
#define DBG(x)                         \
    (void)(cout << "L" << __LINE__     \
                << ": " << #x << " = " \
                << (x) << '\n')
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 110000;
void run_case()
{
    int n, r;
    cin >> n >> r;
    if (n >= 10)
        cout << r << "\n";
    else
        cout << r + 100 * (10 - n) << "\n";
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