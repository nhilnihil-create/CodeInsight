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
    vector<int> cnt_Li(1001);
    for (int i = 0; i < N; i++)
    {
        cnt_Li.at(L.at(i))++;
    }
    vector<int> cnt_shorter(1001);
    int acc = 0;
    for (int l = 0; l < 1001; l++)
    {
        acc += cnt_Li.at(l);
        cnt_shorter.at(l) = acc;
    }

    int res = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            res += cnt_shorter.at(min(1000, L.at(i) + L.at(j) - 1)) - (j + 1);
        }
    }
    cout << res << endl;
    return 0;
}
