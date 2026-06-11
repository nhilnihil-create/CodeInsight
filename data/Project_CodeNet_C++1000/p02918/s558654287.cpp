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
    int x = 0;
    int ans = 0;
    char before = '.';
    for (int i = 0; i < n; i++)
    {
        char now;
        cin >> now;
        if (before == now)
        {
            ans++;
        }
        else
        {
            x++;
        }
        before = now;
    }
    for (int i = 0; i < k; i++)
    {
        if (x > 2)
        {
            x -= 2;
            ans += 2;
        }
        else if (x > 1)
        {
            x -= 1;
            ans += 1;
        }
        else
        {
            break;
        }
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