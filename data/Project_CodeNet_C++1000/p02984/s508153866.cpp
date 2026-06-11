#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> x(n);
    int s = 0;
    rep(i, n)
    {
        cin >> a[i];
        s += a[i];
    }
    s = s / 2;
    int x0 = s;
    for (int i = 1; i < n - 1; i += 2) {
        x0 -= a[i];
    }
    x[0] = x0;
    for (int i = 1; i < n; i++) {
        x[i] = a[i - 1] - x[i - 1];
    }
    rep(i, n)
    {
        cout << x[i] * 2 << " ";
    }

    return 0;
}