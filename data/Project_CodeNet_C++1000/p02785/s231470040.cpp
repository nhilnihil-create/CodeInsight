#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()

using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<int> H(N);
    REP(i, N) cin >> H[i];

    sort(all(H));
    ll result = accumulate(H.begin(), H.begin() + max(N - K, 0), 0ll);
    cout << result << endl;

    return 0;
}
