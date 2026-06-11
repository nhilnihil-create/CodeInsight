#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);


    int n, k;
    cin >> n >> k;

    long res = 0;
    for (int x = k; x <= n + 1; x++) {
        long minsum = (long)x * (x - 1) / 2; //0 + 1 + .. + x - 1
        long maxsum = (long)n * x - minsum;  //n + (n - 1) + ... + (n - (x - 1));
        res += (maxsum - minsum + 1);
        res %= 1000000007;
    }
    cout << res << "\n";

    return 0;
}