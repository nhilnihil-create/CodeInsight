#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> P(N), C(N);
    for (int i = 0; i < N; i++)
    {
        cin >> P[i];
        P[i]--;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> C[i];
    }
    
    long long ans = LONG_LONG_MIN;
    for (int i = 0; i < N; i++)
    {
        int v = i;
        long long cycle_sum = 0;
        long long cycle_cnt = 0;
        while (true)
        {
            cycle_cnt++;
            cycle_sum += C[v];
            v = P[v];
            if (v == i)
            {
                break;
            }
        }
        long long path = 0;
        int cnt = 0;
        while (true)
        {
            cnt++;
            path += C[v];
            if (cnt > K)
            {
                break;
            }
            int num = (K - cnt) / cycle_cnt;
            long long score = path + max(0ll, cycle_sum) * num;
            ans = max(ans, score);

            v = P[v];
            if (v == i)
            {
                break;
            }
            
        }
        
    }
    
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}