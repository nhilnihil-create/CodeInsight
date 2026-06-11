#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1001001001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    ll before = 0;
    ll after = 0;
    for (int i = 0; i < k - 1; i++)
    {
        before += i;
        after += n - i;
    }
    // cout << "before:" << before << endl;
    // cout << "after:" << after << endl;
    for (int i = k - 1; i <= n; i++)
    {
        before = (before + i) % MOD;
        after = (after + n - i) % MOD;
        ans = (ans + after - before + 1 + MOD) % MOD;
    }
    cout << ans << endl;
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
};