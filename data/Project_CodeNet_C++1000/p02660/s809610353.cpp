#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long N;
    cin >> N;
    int sum = 0;
    for (long long i = 2; i*i <= N; i++) {
        int j = 0;
        while (N%i==0) {
            j += 1;
            N /= i;
        }
        if (j > 0) {
            int k = 1;
            while (j >= k) {
                sum += 1;
                j -= k;
                k++;
            }
        }
    }
    if (N > 1) {
        sum += 1;
    }
    cout << sum;
}
