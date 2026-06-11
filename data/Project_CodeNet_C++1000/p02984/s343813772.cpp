#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    int m1 = 0;
    for (int i = 0; i < N; i++) {
        if (i%2 == 0) m1 += A[i];
        else m1 -= A[i];        
    }
    for (int i = 0; i < N; i++) {
        cout << m1 << ' ';
        m1 = (A[i] - m1 / 2) * 2;
    }
    return 0;
}