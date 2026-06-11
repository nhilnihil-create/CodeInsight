#include <bits/stdc++.h>

#define rep(i, N) for (ll i = 0; i < N; i++)
#define repr(i, N) for (ll i = N-1; i >= 0; i--)

using ll = long long;
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vi;

int main() {
    int N;
    cin >> N;
    vi A(N), x(N);
    ll Asum = 0, sumexcN = 0;
    rep(i, N) {
        cin >> A[i];
        Asum += A[i];
        if(i % 2 == 0 && i != N - 1) sumexcN += A[i];
    }

    x[N-1] = Asum/2 - sumexcN;
    repr(i,N-1) {
        x[i] = A[i] - x[i+1];
    }
    rep(i,N) {
        x[i] *= 2;
        cout << x[i] << " ";
    }

    return 0;
}
