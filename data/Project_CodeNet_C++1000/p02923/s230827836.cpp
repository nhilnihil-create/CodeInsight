#include <bits/stdc++.h>
using namespace std;

void solve(int N, vector<int> H)
{
    int res = 0, tmp = 0;
    int h = H.at(0);
    for (int i = 1; i < N; i++)
    {
        if (H.at(i) <= h)
        {
            tmp++;
            res = max(res, tmp);
        }
        else
        {
            tmp = 0;
        }
        h = H.at(i);
    }
    cout << res << endl;
}

int main()
{
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++)
    {
        cin >> H.at(i);
    }
    solve(N, move(H));
    return 0;
}
