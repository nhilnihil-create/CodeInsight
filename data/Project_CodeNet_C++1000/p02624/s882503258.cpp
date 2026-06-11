#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    long long res = 0;
    for (long long  i = 1; i <= N; i++) {
        long long Y = N / i;
        res += Y * (Y+1)/2 * i ;
    }
    cout << res << endl;
    return 0;
}