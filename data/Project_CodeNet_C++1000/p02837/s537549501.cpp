#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < n; ++i)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    int a, ccc = 0;
    int count = 0;
    vector<vector<P>> p(15);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        for (int j = 0; j < a; j++)
        {
            int x, y;
            cin >> x >> y;
            p.at(i).push_back(make_pair(x, y));
        }
    }

    for (int bit = 0; bit < (1 << n); bit++)
    {
        // 正直の時、call
        // 正直同士で整合性に問題ないか確認する
        auto func = [&]() {
            bool ans = true;
            for (int i = 0; i < n; i++)
            {
                if (!(bit & (1 << i)))
                    continue;

                for (int j = 0; j < (int)p[i].size(); j++)
                {
                    int dx = p[i][j].first - 1;
                    int dy = p[i][j].second;

                    if (((bit & (1 << dx)) && dy == 1) ||
                        (!(bit & (1 << dx)) && dy == 0))
                        continue;
                    else
                        ans = false;
                }
            }

            return ans;
        };

        if (func())
        {
            count = 0;
            for (int j = 0; j < n; j++)
            {
                if (bit & (1 << j))
                    count++;
            }
            ccc = max(count, ccc);
        }
    }

    cout << ccc << endl;

    return 0;
}
