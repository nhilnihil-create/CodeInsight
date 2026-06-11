#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L



int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (auto& x : A) cin >> x;
    long long ans = 0;
    sort(A.begin(), A.end());
    for (int i = 0;i < N; i++) {
        for (int j = i +1; j < N; j++) {
            int start = j + 1;
            long long sum = A[i] + A[j] -1;
            auto it = upper_bound(A.begin(), A.end(), sum);
            int dist = distance(A.begin(), it);
            ans += max(0, dist - start);

        }
    }
    cout << ans << "\n";

    return 0;
}