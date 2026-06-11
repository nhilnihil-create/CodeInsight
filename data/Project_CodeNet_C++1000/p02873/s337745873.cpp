#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string S;
    cin >> S;

    int less_cnt = 0;
    int bigger_cnt = 0;

    int start = 0;

    long ans = 0;
    rep(i, S.size())
    {
        if (S.at(i) == '<')
        {
            less_cnt = 0;
            ans += ++bigger_cnt;
        }
        else if (S.at(i) == '>')
        {
            less_cnt++;
            if (less_cnt == 1)
            {
                start = bigger_cnt;
                bigger_cnt = 0;
                if (start == 0)
                {
                    ans += 1;
                }
            }
            else if (less_cnt > 1)
            {
                if (start >= less_cnt)
                {
                    ans += less_cnt - 1;
                }
                else
                {
                    ans += less_cnt;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}