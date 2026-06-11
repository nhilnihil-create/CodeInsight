#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int N;
int A[100100];
int B[100100];

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N;
    rep(i, N) cin >> A[i];
    rep(i, N) {
        if (i%2==0) B[0] += A[i];
        else B[0] -= A[i];
    }
    for (int i=1; i<N; i++) B[i] = 2*A[i-1]-B[i-1];
    rep(i, N) {
        if (i<N-1) cout << B[i] << " ";
        else cout << B[i] << endl;
    }
}