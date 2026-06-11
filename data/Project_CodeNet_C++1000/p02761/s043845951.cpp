#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
int N, M;

int main()
{
    cin >> N >> M;
    vector<int> s(M);
    vector<int> c(M);

    rep(i, 0, M)
    {
        cin >> s[i] >> c[i];
    }

    vector<int> flg(N + 1, -1);
    int ans = 0;
    if (M == 0 && N > 1)
    {
        ans += 1 * pow(10, N - 1);
    }
    rep(i, 0, M)
    {
        if (N > 1 && s[i] == 1 && c[i] == 0)
        {
            ans = -1;
            break;
        }
        if (flg[s[i]] == -1)
        {
            ans += c[i] * pow(10, N - s[i]);
            flg[s[i]] = c[i];
        }
        else
        {
            if (flg[s[i]] != c[i])
            {
                ans = -1;
                break;
            }
        }
    }
    if (ans < pow(10, N - 1) && ans != -1 && N > 1)
    {
        ans += 1 * pow(10, N - 1);
    }

    cout << ans << endl;
    return 0;
}
