#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, N) for (ll i = 0; i < (N); i++)
#define For(i, a, b) for (ll i = (a); i < (b); i++)
#define all(A) (A).begin(), (A).end()

int main(){
    int N;
    cin >> N;
    ll A[N];
    rep(i, N) cin >> A[i];
    ll X[N];
    X[0] = 0;
    rep(i, N) {
        if (i % 2 == 0) X[0] += A[i];
        else X[0] -= A[i];
    }
    rep(i, N - 1) X[i + 1] = (A[i] - X[i] / 2) * 2;

    rep(i, N) {
        cout << X[i];
        if (i != N - 1) cout << " ";
        else cout << endl;
    }


    return 0;
}
