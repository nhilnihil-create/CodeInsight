#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n;
    int a[200000];
    bool dp[1000001];
    for (int i = 0; i < 1000001; i++) {
        dp[i] = true;
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int amax = a[n - 1];

    for (int i = 0; i < n; i++) {
        for (int j = 2; a[i] * j <= amax; j++)
            dp[a[i] * j] = false;
        if (i < n - 1 && a[i] == a[i + 1])
            dp[a[i]] = false;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (dp[a[i]]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}