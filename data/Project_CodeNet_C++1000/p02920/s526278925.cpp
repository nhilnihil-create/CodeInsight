#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair
#define int         int64_t

using namespace std;

typedef pair<int, int> pii;
const int N = 1 << 18 | 1;
const int inf = (int)1e15;

int n, x;
vector<int> cur, top;
set<pii> pq;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "test"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n; n = 1 << n;
    for(int i = 0; i < n; ++i) cin >> x, pq.insert(mp(x, i));
    cur.pb((*pq.rbegin()).fi);
    pq.erase(*pq.rbegin());
    while(pq.size()) {
        top.clear(); bool cando = 1;
        for(int i = 0; i < int(cur.size()); ++i) {
            auto ptr = pq.lower_bound(mp(cur[i], 0));
            if(ptr != pq.begin()) {
               ptr = prev(ptr);
               top.pb((*ptr).fi);
               pq.erase(*ptr);
            } else {cando = 0; break;}
        }
        if(!cando) break;
        for(int x: top) cur.pb(x);
    }
    if(pq.size()) cout << "No";
    else cout << "Yes";
}
