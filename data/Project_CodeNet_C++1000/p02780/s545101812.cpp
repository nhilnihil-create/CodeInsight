#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int N, K;
    double tmp;
    cin >> N >> K;
    vector<double> p(N);
    rep(i,N) {
        cin >> tmp;
        p.at(i) = (tmp + 1.0) / 2.0;
    }
    double sum = 0;
    vector<double> S(N+1);
    rep(i,N) {
        sum += p.at(i);
        S.at(i+1) = sum;
    }
    double ans = 0;
    rep(i,N-K+1) {
        ans = max(ans, S.at(i+K) - S.at(i));
    }
    cout << fixed << setprecision(1) << ans << endl;
}
