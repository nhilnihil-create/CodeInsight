#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    int N, abssum = 0, amax = -10001, amin = 10001;
    cin >> N;
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
        abssum += abs(A[i]);
        amax = max(amax, A[i]);
        amin = min(amin, A[i]);
    }
    cout << abssum - abs(amax) - abs(amin) + abs(amax - amin) << endl;
    sort(A.begin(), A.end());
    int i = 0, j = N - 1;
    while (i + 1 < j) {
        if (A[i + 1] > 0) {
            cout << A[i] << " " << A[j] << endl;
            A[i] -= A[j];
            j--;
        } else {
            cout << A[j] << " " << A[i] << endl;
            A[j] -= A[i];
            i++;
        }
    }
    cout << A[j] << " " << A[i] << endl;
}
