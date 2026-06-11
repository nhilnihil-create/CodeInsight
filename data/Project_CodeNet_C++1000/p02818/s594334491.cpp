#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    ll a, b, k;
    cin >> a >> b >> k;
    if (a >= k)
    {
        a -= k;
    }
    else
    {
        k -= a;
        a = 0;
        b -= k;
        if (b < 0)
        {
            cout << 0 << ' ' << 0 << endl;
            return 0;
        }
    }

    cout << a << ' ' << b << endl;
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
}