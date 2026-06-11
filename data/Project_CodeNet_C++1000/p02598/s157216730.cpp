#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N, K;
    cin >> N >> K;
    vector< int > A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int a_max = 0;
    for (int i = 0; i < N; i++) {
        a_max = max(a_max, A[i]);
    }
    int l = 0, r = a_max, middle;
    while (l + 1 < r) {
        middle = (l + r) / 2;
        long long sum = 0;
        for (int i = 0; i < N; i++) {
            sum += (A[i] + middle - 1) / middle - 1;
        }
        if (sum > K) {
            l = middle;
        } else {
            r = middle;
        }
    }
    printf("%d\n", r);

    return 0;
}
