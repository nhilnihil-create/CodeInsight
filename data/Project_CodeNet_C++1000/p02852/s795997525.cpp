#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N, M;
    string S;
    cin >> N >> M >> S;
    reverse(S.begin(), S.end());
    if (S.front() == 1 || S.back() == 1)
    {
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans;
    int pos = 0;
    while (pos < N)
    {
        bool is_ok = false;
        for (int i = M; i > 0; i--)
        {
            if (i + pos > N)
                continue;

            if (S[i + pos] == '0')
            {
                pos = i + pos;
                ans.push_back(i);
                is_ok = true;
                break;
            }
        }

        if (!is_ok)
        {
            cout << -1 << endl;
            return 0;
        }
    }

    rep(i, ans.size())
    {
        cout << ans[ans.size() - 1 - i] << " ";
    }
    cout << endl;
    return 0;
}