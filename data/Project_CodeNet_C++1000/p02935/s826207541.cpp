#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    rep(i,N) cin >> v.at(i);

    sort(v.begin(), v.end());
    double ans = (v.at(0) + v.at(1)) / 2.0;
    rep(i,N-2) {
        ans = (ans + v.at(i+2)) / 2.0;
    }
    cout << fixed << setprecision(7) << ans << endl;
}
