#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    if (N % 2 != 0) {
        int mn = A[N / 2];
        int mx = B[N / 2];
        cout << mx - mn + 1 << endl;
    } else {
        int mn2 = A[N / 2 - 1] + A[N / 2];
        int mx2 = B[N / 2 - 1] + B[N / 2];
        cout << mx2 - mn2 + 1 << endl;
    }
    return 0;
}