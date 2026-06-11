#include <bits/stdc++.h>

using namespace std;
using llong = long long int;

#define rep(i, n) for (int i = 0; i < ((int)n); ++i)
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

const static int MOD = 1000000007;
const static int INF = 1000000000;
const static int dx[4] = {1, 0, -1, 0};
const static int dy[4] = {0, 1, 0, -1};

/* --------------- template start --------------- */
template <class Abel> 
struct BinaryIndexTree {
    vector<Abel> dat[2];
    Abel UNITY_SUM = 0; // to be set
    
    /* [1, n] */
    BinaryIndexTree(int n) { init(n); }
    void init(int n) { for (int iter = 0; iter < 2; ++iter) dat[iter].assign(n + 1, UNITY_SUM); }
    
    /* a, b are 1-indexed, [a, b) */
    inline void sub_add(int p, int a, Abel x) {
        for (int i = a; i < (int)dat[p].size(); i += i & -i)
            dat[p][i] = dat[p][i] + x;
    }
    inline void add(int a, int b, Abel x) {
        sub_add(0, a, x * -(a - 1)); sub_add(1, a, x); sub_add(0, b, x * (b - 1)); sub_add(1, b, x * (-1));
    }
    
    /* a is 1-indexed, [a, b) */
    inline Abel sub_sum(int p, int a) {
        Abel res = UNITY_SUM;
        for (int i = a; i > 0; i -= i & -i) res = res + dat[p][i];
        return res;
    }
    inline Abel sum(int a, int b) {
        return sub_sum(0, b - 1) + sub_sum(1, b - 1) * (b - 1) - sub_sum(0, a - 1) - sub_sum(1, a - 1) * (a - 1);
    }
    
    /* debug */
    void print() {
        for (int i = 1; i < (int)dat[0].size(); ++i) cout << sum(i, i + 1) << ",";
        cout << endl;
    }
};

template<typename T>
struct UnionFind {
    vector<int> par;
    vector<T> sz;

    UnionFind(int n) {
        par.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; ++i) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find_root(int x) {
        return par[x] == x ? x : par[x] = find_root(par[x]);
    }

    bool same(int x, int y) {
        return find_root(x) == find_root(y);
    }

    void unite(int x, int y) {
        x = find_root(x);
        y = find_root(y);
        if (x == y) return;
        
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
    }

    T size_of_tree(int x) {
        return sz[find_root(x)];
    }
};
/* --------------- template end --------------- */

/* --------------- function start --------------- */
llong my_gcd(llong a, llong b) {
    return (a ? my_gcd(b % a, a) : b);
}
llong my_lcm(llong a, llong b) {
    return a * b / my_gcd(a, b);    
}

llong facmod(llong n) {
    if (n == 0) return 1;

    llong res = n;
    for (int i = n - 1; i > 0; --i) {
        res = (res * i) % MOD;
    }

    return res;
}
llong powmod(llong a, llong n) {
    llong res = 1;
    while (n > 0) {
        if (n & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }

    return res;
}
llong modinv(llong n) {
    return powmod(n, MOD - 2);
}
llong combmod(llong n, llong k) {
    llong res = 1;
    for (int i = 0; i < k; ++i) {
        res = (res * (n - i)) % MOD;
    }
    res = (res * modinv(facmod(k))) % MOD;

    return res;
}

vector<llong> divisors(llong n) {
    vector<llong> ret;
    for(llong i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if((i * i) != n) ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));

    return ret;
}

bool primeNumber(llong n){
    if(n < 2LL) return false;
    else{
        for(llong i = 2LL; i * i <= n; i++){
            if(n % i == 0LL) return false;
        }
        return true;
    }
}
/* --------------- function end --------------- */

int main (int argc, char *argv[]) {
    cin.tie(0); 
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ;
    rep(_, n) {
        int a, b;
        cin >> a >> b;
        PQ.push(make_pair(a, b));
    }
    PQ.push(make_pair(INF, -INF)); // sentinel

    int ans = 0;
    priority_queue<pair<int, int> > tmpPQ;
    for (int i = 1; i <= m; ++i) {
        while (PQ.top().first <= i) {
            pair<int, int> p = PQ.top();
            PQ.pop();
            tmpPQ.push(make_pair(p.second, p.first));
        }
        if (! tmpPQ.empty()) {
            ans += tmpPQ.top().first;
            tmpPQ.pop();
        }
    }

    cout << ans << endl;

    return 0;
}