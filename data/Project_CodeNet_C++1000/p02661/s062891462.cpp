#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)

int main() {
    int N;
    cin >> N;
    int A[N], B[N];
    rep(i, N) cin >> A[i] >> B[i];
    sort(A, A+N);
    sort(B, B+N);
    int medA, medB;
    if(N % 2 == 1) {
        medA = A[(N+1)/2-1];
        medB = B[(N+1)/2-1]; 
    } else {
        medA = (A[N/2-1] + A[N/2]);
        medB = (B[N/2-1] + B[N/2]);
    }
    cout << medB - medA + 1 << endl;
    return 0;
}