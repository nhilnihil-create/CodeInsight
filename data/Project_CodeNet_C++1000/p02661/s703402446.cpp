#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A.at(i) >> B.at(i);
    long long ans;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    if (N % 2 == 1) {
        long middle = (N + 1) / 2 - 1;
        ans = B.at(middle) - A.at(middle) + 1;
    } else {
        long low = N / 2 - 1;
        long high = low + 1;
        ans = (B.at(high) + B.at(low)) - (A.at(high) + A.at(low)) + 1;
    }
    cout << ans << endl;

}
