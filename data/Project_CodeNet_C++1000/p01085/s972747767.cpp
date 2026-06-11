#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> ans;
    while (1)
    {
        int m, min, max;
        cin >> m >> min >> max;
        if (m + min + max == 0)
        {
            break;
        }

        vector<int> scoreList;
        for (int i = 0; i < m; ++i)
        {
            int input;
            cin >> input;
            scoreList.push_back(input);
        }

        int maxDif = 0, answer = min;
        for (int i = min; i <= max; ++i)
        {
            int dif = scoreList[i - 1] - scoreList[i];

            if (dif >= maxDif)
            {
                maxDif = dif;
                answer = i;
            }
        }

        ans.push_back(answer);
    }

    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << endl;
    }
}
