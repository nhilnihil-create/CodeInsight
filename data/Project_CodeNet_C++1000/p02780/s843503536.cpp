#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    long double p[N];
    for (int i = 0; i < N; i++) {
        cin >> p[i];
        p[i] = (p[i] + 1) / 2.0;
    }

    long double sum = 0;
    for (int i = 0; i < K; i++) {
        sum += p[i];
    }
    long double ans = sum;
    for (int i = 0; i < N - K; i++) {
        sum = sum - p[i] + p[K + i];
        ans = max(ans, sum);
    }
    cout << setprecision(20) << ans << endl;
    return 0;
}