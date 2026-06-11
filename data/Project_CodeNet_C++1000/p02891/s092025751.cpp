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
    string s;
    ll k;
    cin >> s >> k;
    int n = s.size();
    vector<ll> sq(n);
    sq[0] = 1;
    int idx = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            sq[idx]++;
        }
        else
        {
            idx++;
            sq[idx]++;
        }
    }
    if (idx == 0) // １種類の文字で構成されている場合
    {
        cout << (n * k) / 2 << endl;
        return 0;
    }
    ll ans = 0;
    for (int i = 0; i <= idx; i++)
    {
        ans += (sq[i] / 2);
    }
    ans *= k;
    if (s[0] == s[n - 1])
    {
        ans -= ((sq[0] / 2) + (sq[idx] / 2) - ((sq[0] + sq[idx]) / 2)) * (k - 1);
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
            cout << " ";
        cout << v[i];
    }
    cout << endl;
}
