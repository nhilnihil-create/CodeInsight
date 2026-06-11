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

void run_case()
{
    int n;
    cin >> n;
    vector<int> B(n), A(n + 1);
    for (int i = 1; i <= n - 1; i++)
        cin >> B[i];
    int ans = 0;
    A[1] = B[1], A[n] = B[n - 1];
    ans += (A[1] + A[n]);
    for (int i = 2; i <= n - 1; i++)
    {
        A[i] = min(B[i - 1], B[i]);
        ans += A[i];
    }
    cout << ans << "\n";
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