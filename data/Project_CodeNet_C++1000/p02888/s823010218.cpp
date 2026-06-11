#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> L(N);
    for (int i = 0; i < N; i++)
    {
        cin >> L.at(i);
    }

    sort(L.begin(), L.end());
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int l = j + 1;
            int r = lower_bound(L.begin(), L.end(), L.at(i) + L.at(j)) - L.begin();
            res += max(0, r - l);
        }
    }
    cout << res << endl;
    return 0;
}
