#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> u(N - 1), v(N - 1);
    for (int i = 0; i < N - 1; i++)
    {
        cin >> u.at(i) >> v.at(i);
    }

    int64_t sum_v = 0;
    for (int i = 1; i <= N; i++)
    {
        sum_v += (int64_t)i * (N - i + 1);
    }

    int64_t sum_e = 0;
    for (int i = 0; i < N - 1; i++)
    {
        int vl = min(u.at(i), v.at(i)), vr = max(u.at(i), v.at(i));
        sum_e += (int64_t)vl * (N - vr + 1);
    }

    cout << sum_v - sum_e << endl;
    return 0;
}
