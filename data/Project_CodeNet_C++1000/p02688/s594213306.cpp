#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
using ll = long long;

int main(void)
{
    int N, K;
    cin >> N >> K;
    vector<int> count(N, 0);

    for (int i = 0; i < K; i++)
    {
        int d;
        cin >> d;
        for (int j = 0; j < d; j++)
        {
            int a;
            cin >> a;
            a--;
            count[a]++;
        }
    }

    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        if (count[i] == 0)
        {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
