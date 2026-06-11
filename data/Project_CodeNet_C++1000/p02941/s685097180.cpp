#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair

using namespace std;

const int N = int(2e5) + 7;
typedef pair<int, int> pii;

int n, a[N], b[N], res, Q[N];

int prv(int i) {return i - 1 >= 1? i - 1: n;}
int nxt(int i) {return i + 1 <= n? i + 1: 1;}
priority_queue<pii> pq;
bool Check(int i) {return b[i] > a[i] && b[i] - a[i] >= b[prv(i)] + b[nxt(i)];}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "test"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) {
        cin >> b[i];
        if(Check(i)) pq.push(mp(b[i], i)), Q[i] = 1;
    }
    ll ans = 0;
    while(pq.size()) {
       pii top = pq.top(); pq.pop(); Q[top.se] = 0;
       int x = b[prv(top.se)], y = b[top.se], z = b[nxt(top.se)];
       if(y - a[top.se] >= x + z) {
         b[top.se] -= (y - a[top.se]) / (x + z) * (x + z);
         ans += (y - b[top.se]) / (x + z);
       } else break;
       if(Check(top.se)) pq.push(mp(b[top.se], top.se)), Q[top.se] = 1;
       x = prv(top.se);
       for(int i = 1; i <= 2; ++i, x = prv(x))
          if(Check(x) && !Q[x]) pq.push(mp(b[x], x)), Q[x] = 1;
       x = nxt(top.se);
       for(int i = 1; i <= 2; ++i, x = nxt(x))
          if(Check(x) && !Q[x]) pq.push(mp(b[x], x)), Q[x] = 1;
    }
    for(int i = 1; i <= n; ++i) {
        if(a[i] != b[i]) return cout << -1, 0;
    }
    cout << ans;
}
