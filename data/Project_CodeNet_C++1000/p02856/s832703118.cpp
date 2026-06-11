#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()

using namespace std;

using ll = long long;

int main() {
    int M;
    cin >> M;
    vector<ll> d(M), c(M);
    REP(i, M) cin >> d[i] >> c[i];

    ll c_sum = accumulate(all(c), 0ll);
    ll digit_sum = 0;
    REP(i, M) digit_sum += d[i] * c[i];
    ll result = c_sum - 1 + (digit_sum - 1) / 9;
    cout << result << endl;

    return 0;
}