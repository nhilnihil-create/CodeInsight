#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> s(N);
    int Xi, Li;
    for (int i = 0; i < N; i++)
    {
        cin >> Xi >> Li;
        s.at(i) = make_pair(Xi + Li, Xi - Li);
    }
    sort(s.begin(), s.end());

    int res = 0;
    int mx = -1e9;
    for (int i = 0; i < N; i++)
    {
        int li = s.at(i).second, ri = s.at(i).first;
        if (mx <= li)
        {
            res++;
            mx = ri;
        }
    }
    cout << res << endl;
}