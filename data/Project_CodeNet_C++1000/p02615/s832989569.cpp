#include <bits/stdc++.h>
using namespace std;




























int main () {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort (A.begin(), A.end());
    reverse (A.begin(), A.end());
    long long sum = 0;
    for (int i = 1; i < N; i++) {
        sum += A[i / 2];
    }
    cout << sum << endl;
}