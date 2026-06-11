#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    int n = N;
    vector<int> v(n), w(n);
    for (int i = 0; i < N; i++)
        cin >> v[i], --v[i];
    for (int i = 0; i < N; i++)
        cin >> w[i];

    ll ans = -1e18;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        int p = v[i];
        ll sum = 0, max_sum = w[p];
        ll sum_cycle = 0;
        while (p != i)
        {
            temp.push_back(w[p]);
            sum_cycle += w[p];
            max_sum = max(max_sum, sum_cycle);
            p = v[p];
        }
        temp.push_back(w[i]);
        sum_cycle += w[i];
        max_sum = max(max_sum, sum_cycle);
        int len = temp.size();
        if (sum_cycle <= 0)
            sum = max_sum;
        else
        {
            int number_cycle = K / len;
            int rem = K - number_cycle * len;
            ll temp_sum = 0;
            ll maxx = 0;
            for (int t = 0; t < rem; t++)
            {
                temp_sum += temp[t];
                maxx = max(temp_sum, maxx);
            }
            sum += maxx + sum_cycle * number_cycle;
            ll next_sum = 0;
            if (number_cycle > 1)
            {
                next_sum = (number_cycle - 1) * sum_cycle;
                next_sum += max_sum;
            }
            sum = max(sum, next_sum);
        }
        ans = max(sum, ans);
    }
    cout << ans;
}