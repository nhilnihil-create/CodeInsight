#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main() {
    int N;
    double c, ans;

    cin >> N;

    vector<double> A(N);

    rep(i,N) {
        cin >> A[i];
        c += 1/A[i];
    }

    ans = 1/c;

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
    
}