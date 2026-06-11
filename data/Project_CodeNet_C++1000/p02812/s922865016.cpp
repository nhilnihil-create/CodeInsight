#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;
const int MOD = 1e9 + 7;

int main()
{
    int n;
    string s, t = "ABC";
    cin >> n >> s;

    int res = 0;
    rep(i, n)
    {
        if (s[i] == 'A')
        {
            int flag = 0;
            rep(j, 3)
            {
                if (s[i + j] != t[j])
                {
                    flag++;
                }
            }
            if (!flag)
                res++;
        }
    }
    cout << res << endl;
    return (0);
}
