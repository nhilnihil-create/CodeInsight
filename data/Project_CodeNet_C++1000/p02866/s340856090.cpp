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
    int n;
    cin >> n;
    int origin;
    cin >> origin;
    if (origin != 0)
    {
        cout << 0 << endl;
        return 0;
    }
    map<int, int> mp;
    mp[0] = 1;
    ll ans = 1;
    for (int i = 1; i < n; i++)
    {
        int d;
        cin >> d;
        ++mp[d];
    }
    int cnt = 1;
    for (int i = 1;; i++)
    {
        if (!mp.count(i))
        {
            if (cnt == n)
            {
                cout << ans << endl;
                return 0;
            }
            else
            {
                cout << 0 << endl;
                return 0;
            }
        }
        for (int j = 0; j < mp[i]; j++)
        {
            ans = (ans * mp[i - 1]) % 998244353;
            ++cnt;
        }
    }
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