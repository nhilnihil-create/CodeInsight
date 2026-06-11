#include <bits/stdc++.h>          
using namespace std;               

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }
    int sumA = 0, count = N;
    for (int i=0; i<N; i++) {
        sumA += A[i];
    }
    if (sumA % (4*M) == 0) {
        for (int i=0; i<N; i++) {
            if (A[i] < sumA/(4*M)) {
                count--;
            }
        }
    }
    else {
        for (int i=0; i<N; i++) {
            if (A[i] <= sumA/(4*M)) {
                count--;
            }
        }
    }
    string ans = "No";
    if (count >= M) {
        ans = "Yes";
    }
    cout << ans << endl;
}