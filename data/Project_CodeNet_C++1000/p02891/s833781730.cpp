#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    long K;
    cin >> S;
    cin >> K;

    long ans = 0;

    char c = S.at(0);
    long cnt = 1;
    for (long unsigned int i = 1; i < S.size(); i++)
    {
        if (c == S.at(i))
        {
            cnt++;
        }
        else
        {
            c = S.at(i);
            if (cnt > 1)
            {
                ans += cnt / 2;
                cnt = 1;
            }
        }
    }

    if (cnt == S.size())
    {
        cout << (K * cnt) / 2 << endl;
        return 0;
    }

    ans += cnt / 2;
    ans *= K;

    long tmp = cnt;
    for (long unsigned int i = 0; i < S.size(); i++)
    {
        if (c == S.at(i))
        {
            cnt++;
        }
        else
        {
            break;
        }
    }

    ans += ((cnt / 2) - (tmp / 2 + (cnt - tmp) / 2)) * (K - 1);

    cout << ans << endl;

    return 0;
}