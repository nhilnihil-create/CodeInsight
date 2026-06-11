#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll unsigned long long int
using namespace std;

int main() {

    int N;
    cin >> N;

    vector<int> A(N), B(N), C(N-1);
    int sum = 0;

    rep(i, N) cin >> A[i];
    rep(i, N) {
        cin >> B[i];
        sum += B[i];
    }
    rep(i, N-1) cin >> C[i];

    rep(i, N-1) {
        if (A[i+1] - A[i] == 1) sum += C[A[i]-1];

    }

    cout << sum << endl;

    return 0;
}
