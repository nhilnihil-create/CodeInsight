#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int digit(int n)
{
    if (n < 10)
    {
        return 1;
    }
    return digit(n / 10) + 1;
}

string int_to_string(int n)
{
    string res = "";

    while (n)
    {
        char tmp = (n % 10) + '0';
        res = tmp + res;
        n /= 10;
    }
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> s(m), c(m);
    rep(i, m) cin >> s[i] >> c[i];

    rep(i, 1000)
    {
        if (n != digit(i))
        {
            continue;
        }

        bool flag = true;
        rep(j, m)
        {
            string st_num = to_string(i);
            if (st_num[s[j] - 1] - '0' != c[j])
            {
                flag = false;
            }
        }
        if (flag)
        {
            cout << i << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
    return (0);
}
