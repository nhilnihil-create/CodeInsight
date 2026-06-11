#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)
#define bg begin()
#define ed end()
#define all(x) x.bg, x.ed
#define vi vector<int>
template <class t, class u>
void chmax(t &a, u b)
{
    if (a < b)
        a = b;
}
template <class t, class u>
void chmin(t &a, u b)
{
    if (b < a)
        a = b;
}

int main()
{
    string s;
    cin >> s;
    vector<ll> n(s.length() + 1, 0);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '<')
        {
            chmax(n[i + 1], n[i] + 1);
        }
    }
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == '>')
        {
            chmax(n[i], n[i + 1] + 1);
        }
    }

    cout << std::accumulate(all(n), ll(0)) << endl;
    return 0;
}