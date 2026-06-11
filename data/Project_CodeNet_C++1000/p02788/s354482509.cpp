#include <bits/stdc++.h>

using namespace std;

#define pos first
#define health second

struct BIT {
    vector<long long> tree;
    BIT(int n) : tree(n + 2){}

    void upd(int p , long long v) {
        for (int i = ++p ;i < tree.size() ; i += i & -i)
            tree[i] += v;
    }

    long long get(int p) {
        long long sum = 0;
        for (int i = ++p; i ; i -= i & -i)
            sum += tree[i];
        return sum;
    }

    long long query(int l , int r) {
        if (r < l) return 0;
        return get(r) - get(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.in" , "r" , stdin);
#endif
    int n , D , A;
    cin >> n >> D >> A;

    map<long long , int> NEW;

    vector<pair<int , int> > mon(n);
    for (int i = 0 ;i < n ;i++) {
        cin >> mon[i].pos >> mon[i].health;
        NEW[mon[i].pos];
        NEW[mon[i].pos + 2ll * D];
    }

    int sz = 0;
    for (auto &p : NEW)
        p.second = sz++;

    BIT bit(sz);

    sort(mon.begin() , mon.end());

    long long ans = 0;
    for (int i = 0 ;i < n ;i++) {
        long long damage = bit.query(NEW[mon[i].pos] , sz);
        if (damage >= mon[i].health) continue;
        int rem = mon[i].health - damage;
        int need = (rem + A - 1) / A;
        ans += need;
        bit.upd(NEW[mon[i].pos + 2ll * D] , need * 1ll * A);
    }

    cout << ans;
}
