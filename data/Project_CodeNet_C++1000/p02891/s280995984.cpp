#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (ll i = (ll)(start); i < (ll)(n); ++i)
static const ll INFTY = 1L << 62L;
ll solver(string S, ll K)
{
    ll ans = 0, tmp = 0;
    bool flag = true;
    rep(i, 0, S.size() - 1)
    {
        if (S[i] != S[i + 1])
        {
            flag = false;
            break;
        }
    }
    if (flag)
        ans = S.size() * K / 2;
    else
    {
        ll front = 0, back = S.size() - 1, cnt = 0;
        if (S.front() == S.back())
        {
            rep(i, 1, S.size())
            {
                if (S.front() != S[i])
                {
                    front = i;
                    break;
                }
            }
            for (int i = S.size() - 2; i >= 0; --i)
            {
                ++cnt;
                if (S.back() != S[i])
                {
                    back = i;
                    break;
                }
            }
            ans = (front + cnt) / 2 * (K - 1);
            rep(i, 0, front)
            {
                if (S[i] == S[i + 1])
                {
                    ++ans;
                    ++i;
                }
            }
            rep(i, back + 1, S.size())
            {
                if (S[i] == S[i + 1])
                {
                    ++ans;
                    ++i;
                }
            }
        }
        rep(i, front, back)
        {
            if (S[i] == S[i + 1])
            {
                ++tmp;
                ++i;
            }
        }
        ans += tmp * K;
    }
    return ans;
}
int main()
{
    string S;
    ll K;
    cin >> S >> K;
    cout << solver(S, K) << endl;
}