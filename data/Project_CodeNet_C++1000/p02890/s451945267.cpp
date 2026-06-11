#include <bits/stdc++.h>
using namespace std;

const int MAX = 300100;


int main() {
    long long N, x; cin >> N;
    long long sum[MAX], c[MAX];
    for (int i = 0; i < MAX; i++) {
        sum[i] = 0;
        c[i] = 0;
    }
    for(long long i = 1; i <= N; i++) {
        cin >> x;
        c[x]++;
        sum[c[x]]++;
    }
    for (long long i = 1; i <= N; i++) sum[i] += sum[i - 1];
    for (long long i = 1; i <= N; i++) {
        long long l = 1, r = N, ans = 0, mid;
        while (l <= r) {
            mid = (r - l) / 2 + l;
            if (mid * i <= sum[mid]) {
                ans = mid;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        cout << ans << endl;
    }
    return 0;
}