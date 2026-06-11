#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;
using namespace std;

const int LIM = 1e5;
int N, P[LIM], idx[LIM];
ll ans;

int main() {
    cin >> N;
    rep(i, N) {
        cin >> P[i];
        P[i]--;
    }
    rep(i, N) idx[P[i]] = i;

    set<int> S;
    for (int x = N - 1; x >= 0; x--) {
        int i = idx[x];
        S.insert(i);
        // calc l
        vector<int> l(2, -1);
        auto it = S.find(i);
        rep(j, 2) {
            if (it == S.begin()) break;
            it--;
            l[j] = *it;
        }
        // calc r
        vector<int> r(2, N);
        it = S.find(i);
        rep(j, 2) {
            it++;
            if (it == S.end()) break;
            r[j] = *it;
        }
        // calc ans
        int ls0 = i - l[0], ls1 = l[0] - l[1];
        int rs0 = r[0] - i, rs1 = r[1] - r[0];
        ll c = (ll)ls0 * rs1 + (ll)ls1 * rs0;
        ans += c * (x + 1);
    }
    cout << ans << endl;
}