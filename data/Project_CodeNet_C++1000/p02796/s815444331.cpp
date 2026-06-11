#include <bits/stdc++.h>

#define FOR(i, l, r) for(ll i = l; i < r; i++)
#define rep(i, N) FOR(i, 0, N)

using ll = long long int;
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    int n; cin >> n;
    vector<P> RL(n);
    rep(i,n) {
        int x,l;
        cin >> x >> l;
        RL[i] = P(x+l, x-l);
    }

    sort(RL.begin(), RL.end());
    int ans = 0;

    int gx = -1e9-1;
    rep(i, n){
        if(gx <= RL[i].second) {
            ans++;
            gx = RL[i].first;
        }
    }


    cout << ans << "\n";
    return 0;
}
