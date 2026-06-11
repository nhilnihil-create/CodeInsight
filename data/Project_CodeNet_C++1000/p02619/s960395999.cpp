#include <bits/stdc++.h>
using namespace std;

int main()
{
    int D;
    cin >> D;

    vector<int> C(26);
    vector<vector<int>> S(D, vector<int>(26));

    for (int i = 0; i < 26; i++)
    {
        cin >> C.at(i);
    }

    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            cin >> S.at(i).at(j);
        }
    }

    vector<int> T(D);
    for (int i = 0; i < D; i++)
    {
        cin >> T.at(i);
    }

    int point = 0;
    int t;
    vector<int> last(26);
    for (int d = 0; d < D; d++)
    {
        t = T.at(d);
        last.at(t -1) = d + 1;
        for (int j = 0; j < 26; j++)
        {
            point -= C.at(j) * (d + 1 - last.at(j));
        }

        point += S.at(d).at(t-1);
        cout << point << endl;
    }

    return 0;
}