#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    string S;
    cin >> S;

    ll n = S.size();
    vector<ll> a(n + 1, -1);

    bool flag = false;
    for (ll i = 0; i < n; ++i)
    {
        if (S[i] == '<')
        {
            if (flag)
            {
                a[i] = a[i - 1] + 1;
            }
            else
            {
                a[i] = 0;
                flag = true;
            }
            if (i == n - 1)
            {
                a[i + 1] = a[i] + 1;
            }
        }
        else
        {
            flag = false;
        }
    }

    flag = false;
    for (ll i = n - 1; i >= 0; --i)
    {
        if (S[i] == '>')
        {
            if (flag)
            {
                a[i + 1] = a[i + 2] + 1;
            }
            else
            {
                flag = true;
                a[i + 1] = 0;
            }
            if (i == 0)
            {
                a[i] = a[i + 1] + 1;
            }
        }
        else
        {
            flag = false;
        }
    }

    ll ans = 0;
    REP(i, n + 1)
    {
        if (a[i] == -1)
        {
            a[i] = max(a[i - 1] + 1, a[i + 1] + 1);
        }
        ans += a[i];
    }

    cout << ans << endl;
}
