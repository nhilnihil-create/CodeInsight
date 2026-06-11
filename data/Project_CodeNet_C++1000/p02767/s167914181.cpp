#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int X[N];
    for (int i = 0; i < N; i++) cin >> X[i];

    int ans = INT_MAX;
    for (int i = 1; i <= 100; i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) {
            sum += pow(X[j] - i, 2);
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}