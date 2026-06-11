#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
#define int long long

const int N = 2e5 + 2, inf = 1e18;

vector<array<int,2>> a;

int get(int i, int j) {
    int dist = abs(a[i][0] - a[j][0]) + abs(a[i][1] - a[j][1]);
    return dist;
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    a.resize(n);
    vector<int> pos, neg;

    FOR(i,0,n-1) {
        cin >> a[i][0] >> a[i][1];
        pos.push_back(a[i][0] + a[i][1]);
        neg.push_back(a[i][0] - a[i][1]);
    }

    int ans = 0;
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    ans = max({ans, pos.back() - pos[0], neg.back() - neg[0]});
    cout << ans;
}
