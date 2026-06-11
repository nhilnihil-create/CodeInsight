#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define _READ freopen("input.txt", "r", stdin);
#define _FAST                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
void solve()
{
    int n, k, r, s, p;
    cin >> n >> k >> r >> s >> p;
    string t;
    cin >> t;
    int ans = 0;
    vector<int> R(n), S(n), P(n);

    for (int i = 0; i <k; i++)
    {
        if (t[i] == 'r')
        {
            S[i] = 0;
            R[i] = 0;
            P[i] = p;
            //ans+=p+s;
        }
        if (t[i] == 'p')
        {
            S[i] = s;
            R[i] = 0;
            P[i] = 0;
            // ans+=r+s;
        }
        if (t[i] == 's')
        {
            S[i] = 0;
            R[i] = r;
            P[i] = 0;
            //ans+=p+r;
        }
        int pos = i;
        for (int j = i + k; j < n; j += k)
        {
            if (t[j] == 'r')
            {
                S[j] += max(R[j - k], P[j - k]);
                R[j] += max(P[j - k], S[j - k]);
                P[j] += max(S[j - k], R[j - k]) + p;
                //ans+=p+s;
            }
            if (t[j] == 's')
            {
                S[j] += max(R[j - k], P[j - k]);
                R[j] += max(P[j - k], S[j - k]) + r;
                P[j] += max(S[j - k], R[j - k]); //+p;
                //ans+=r+p;
            }
            if (t[j] == 'p')
            {
                S[j] += max(R[j - k], P[j - k]) + s;
                R[j] += max(P[j - k], S[j - k]);
                P[j] += max(S[j - k], R[j - k]); //+p;
                //ans+=r+s;
            }
            pos = j;
        }
        ans += max({R[pos], P[pos], S[pos]});
    }
    cout << ans;
}
int32_t main()
{

   // _READ
     _FAST
    int t;
    t = 1;
    while (t--)
        solve();

    return 0;
}