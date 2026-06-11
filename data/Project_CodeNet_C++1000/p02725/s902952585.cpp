#include <bits/stdc++.h>
using namespace std;
using ll = long long; //10^19 < 9223372036854775807
#define REP(i,n) for(ll i=0;i<ll(n);i++)

int main(void)
{
    int N, K;
    cin >> K >> N;

    vector<int> A(N);
    REP (i, N) {
        cin >> A[i];
    }

    vector<int> B(N);
    int maxValue = -1;
    int total = 0;

    REP (i, N) {

        if (i < N-1) {
            B[i] = abs(A[i] - A[i+1]);
        }
        else {
            B[i] = abs(K - A[N-1] + A[0]);
        }

        if (maxValue < B[i]) {
            maxValue = B[i];
        }

        total += B[i];

    }

    cout << total - maxValue << endl;

    return 0;
}
