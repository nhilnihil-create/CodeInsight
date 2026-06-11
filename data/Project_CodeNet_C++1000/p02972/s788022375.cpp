#include <bits/stdc++.h>

#define rep(i, N) for (ll i = 0; i < N; i++)
#define rep1(i, N) for (ll i = 1; i <= N; i++)
#define repr(i, N) for (ll i = N-1; i >= 0; i--)

using ll = long long;
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vi;

int main() {
    int N, M = 0;
    cin >> N;
    vi a(N), b(N);
    rep(i, N) cin >> a[i];
    repr(i, N) {
        ll asum = 0;
        rep1(j, N/(i+1) - 1) {
            asum += b[i + j*(i+1)];
        }
        asum %= 2;
        b[i] = (a[i] - asum + 2)%2;
        if(b[i] == 1) M++;
    }

    cout << M << "\n";
    rep(i, N) {
        if(b[i] == 1) cout << (i+1) << " ";
    }
    
    return 0;
}
