#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<double> A(N);
    rep(i, N){
        cin >> A[i];
    }

    long double ans = 0;
    rep(i, N){
        double a = 1.0 / A[i];
        ans += a;
    }

    ans = 1.0 / ans;

    cout << ans << endl;

    return 0;
}