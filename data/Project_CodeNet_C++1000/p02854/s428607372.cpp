#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<long long> A(N);
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
        sum += A.at(i);
    }
    long long left = 0;
    for (int i = 0; i < N; i++) {
        left += A.at(i);
        sum -= A.at(i);
        if (left >= sum) {
            long long a = sum + 2 * A.at(i) - left;
            cout << min(a, left - sum) << endl;
            return 0;
        }
    }
}