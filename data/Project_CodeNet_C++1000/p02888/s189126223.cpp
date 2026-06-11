#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

 

int main() {
    int N;
    int k = 3;
    cin >> N;
    vector<int> L(N);
    rep(i,N) cin >> L.at(i);
    sort(L.begin(), L.end());
    int ans = 0;
    rep(i,N) for (int j = i + 1; j < N; ++j) {
        int idx_distance = distance(L.begin() + j, lower_bound(L.begin(), L.end(), L.at(i)+L.at(j)));
        ans += max(0, idx_distance - 1);
    }
    cout << ans << endl;
}
