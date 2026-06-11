#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    double ans = (A[0] + A[1]) / 2.0;

    for(int i=2; i<N; i++) {
        ans = ans / 2.0 + A[i] / 2.0;
    }
    cout << ans << endl;
}