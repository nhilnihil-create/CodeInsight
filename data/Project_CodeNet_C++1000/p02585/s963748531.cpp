#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    unordered_map<int, int> P(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> P[i];
        --P[i];
    }
    vector<int> C(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> C[i];
    }

    long ans = -1e18;
    for (int i = 0; i < N; ++i)
    {

        long cycle_cnt = 0;
        long cycle_sum = 0;
        int pos = i;
        for (int j = 0; j < N; ++j)
        {
            ++cycle_cnt;
            cycle_sum += C[pos];
            pos = P[pos];
            if (pos == i)
            {
                break;
            }
        }

        long acc_score = 0;
        pos = i;

        for (int j = 0; j < cycle_cnt; ++j)
        {
            if (j >= K)
            {
                break;
            }
            acc_score += C[pos];
            long score = acc_score + max(0l, cycle_sum) * ((K - j - 1) / cycle_cnt);
            ans = max(ans, score);
            pos = P[pos];
        }
    }

    cout << ans << endl;
}
