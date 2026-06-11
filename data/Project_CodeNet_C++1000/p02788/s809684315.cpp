#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;

ll tree[N << 2], lazy[N << 2];

void propagate(int node, int l, int r){
    if(lazy[node] == 0) return;
    if(l != r){
        lazy[node << 1] += lazy[node];
        lazy[node << 1 | 1] += lazy[node];
    }
    tree[node] += lazy[node];
    lazy[node] = 0;
}

void update(int node, int l, int r, int a, int b, int val){
    if(r < a || l > b) return;
    propagate(node, l, r);
    if(l >= a && r <= b){
        lazy[node] = val;
        propagate(node, l, r);
        return;
    }
    int mid = l + r >> 1;
    update(node << 1, l, mid, a, b, val);
    update(node << 1 | 1, mid + 1, r, a, b, val);
}

ll get(int node, int l, int r, int idx){
    propagate(node, l, r);
    if(l == r){
        return tree[node];
    }
    int mid = l + r >> 1;
    if(idx <= mid) return get(node << 1, l, mid, idx);
    return get(node << 1 | 1, mid + 1, r, idx);
}

pair<int, ll> p[N];
int a[N];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n, dis, dam;
    cin >> n >> dis >> dam;
    for(int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
        a[i] = p[i].first;
    }
    sort(p, p + n);
    sort(a, a + n);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll tmp = p[i].second - get(1, 0, n - 1, i);
        if(tmp <= 0) continue;
        ll cost = tmp - tmp % dam;
        if(tmp % dam) cost += dam;
        ans += cost / dam;
        int idx = upper_bound(a, a + n, a[i] + 2 * dis) - a;
        idx--;
        update(1, 0, n - 1, 0, idx, cost);
    }
    cout << ans;

    return 0;
}
