#include <iostream>
#include <vector>
using namespace std;

long long fabs (long long n) {
    if (n < 0) return -n;
    else return n;
}

int main() {
    int n;
    cin >> n;
    vector<long long> sum(n+1);
    for (int i=0; i<n; i++) {
        long long num;
        cin >> num;
        sum[i+1] = sum[i] + num;
    }
    long long ans = 10101010101;
    for (int i=1; i<n; i++) {
        long long dist = (sum[n]-sum[i]) -sum[i];
        ans = min(ans, abs(dist));
    }
    cout << ans << endl;
}