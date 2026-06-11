#include <bits/stdc++.h>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0);
#define ll long long int
#define rep(i, n) for (ll i = 0; i < (n); i++)

using namespace std;
ll MOD = 1000000007;

bool isPrime(ll n) {
    if (n == 1) {
        return false;
    }
    int i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            return false;
        }
        i += 1;
    }
    return true;
}

ll binarySearchLesserOrEqualElement(ll target, ll *arr, ll end) {
    ll low = 1, high = end;
    ll ans = -1;
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (arr[mid] <= target) {
            ans = mid;
            low = mid + 1;
        } else
            high = mid - 1;
    }
    return ans;
}

bool isOdd(ll num) {
    return num % 2;
}

ll ff(ll num) {
    return num % MOD;
}

ll max(ll num1, ll num2) {
    if (num1 > num2) {
        return num1;
    }
    return num2;
}

ll combination(ll n, ll r) {
    ll result = 1;
    for (int i = r; i <= n; ++i) {
        result *= i;
    }
    return result;
}

ll mod(ll f) {
    if (f >= 0) {
        return f;
    }
    return -f;
}

class Graph {
    ll v;
    list<ll> *adj;

public:
    vector<ll> cc;
    bool *visited;
    ll *parent;

public:
    Graph(ll v) {
        this->v = v;
        parent = new ll[v];
        adj = new list<ll>[v];
        visited = new bool[v];
        for (int i = 0; i < v; ++i) {
            visited[i] = false;
        }
    }

public:
    void addEdge(ll vertex1, ll vertex2) {
        adj[vertex1].push_back(vertex2);
        adj[vertex2].push_back(vertex1);
    }

public:
    void findCC() {
        for (int i = 0; i < v; ++i) {
            if (!visited[i]) {
                cc.push_back(i);
                dfs(i);
            }
        }
    }

public:
    bool bfsPath(ll i, ll j) {
        visited = new bool[v];
        for (int i = 0; i < v; ++i) {
            visited[i] = false;
        }
        bfs(i, j);
        return visited[j];
    }

private:
    void bfs(ll i, ll j) {
        queue<ll> open;
        open.push(i);
        visited[i] = true;
        while (!open.empty()) {
            i = open.front();
            for (auto it = adj[i].begin(); it != adj[i].end(); ++it) {
                if (!visited[*it]) {
                    open.push(*it);
                    visited[*it] = true;
                    parent[*it] = i;
                }
            }
            open.pop();
        }
    }

private:
    void dfs(ll i) {
        visited[i] = true;
        for (auto it = adj[i].begin(); it != adj[i].end(); ++it) {
            if (!visited[*it])
                dfs(*it);
        }
    }
};

class SegmentTree {
    ll n;
    ll t[4 * 100000];
    // remember to change the value of array size
public :
    SegmentTree(ll a[], ll n) {
        this->n = n;
        buildTree(a, 1, 0, n - 1);
    }

private:
    ll functionValue(ll a, ll b) {
        return min(a, b);
    }

private:
    void buildTree(ll a[], ll currVertex, ll treeStart, ll treeEnd) {
        if (treeStart == treeEnd) {
            t[currVertex] = a[treeStart];
        } else {
            ll treeMid = (treeStart + treeEnd) / 2;
            buildTree(a, currVertex * 2, treeStart, treeMid);
            buildTree(a, currVertex * 2 + 1, treeMid + 1, treeEnd);
            t[currVertex] = functionValue(t[currVertex * 2], t[currVertex * 2 + 1]);
        }
    }

public:
    ll sum(ll left, ll right) {
        return (sum(1, 0, n - 1, left, right));
    }

public:
    ll sum(ll currVertex, ll tl, ll tr, ll left, ll right) {
        if (left > right) {
            return 0;
        }
        if (left == tl && right == tr) {
            return t[currVertex];
        }
        ll tm = (tl + tr) / 2;
        return functionValue(sum(currVertex * 2, tl, tm, left, min(tm, right)),
                             sum(currVertex * 2 + 1, tm + 1, tr, max(left, tm + 1), right));
    }

public:
    ll minimum(ll currVertex, ll tl, ll tr, ll left, ll right) {
        if (left > right) {
            return 0;
        }
        if (left == tl && right == tr) {
            return t[currVertex];
        }
        ll tm = (tl + tr) / 2;
        return functionValue(minimum(currVertex * 2, tl, tm, left, min(tm, right)),
                             minimum(currVertex * 2 + 1, tm + 1, tr, max(left, tm + 1), right));
    }

public:
    void update(ll pos, ll value) {
        update(1, 0, n - 1, pos, value);
    }

public:
    void update(ll v, ll tl, ll tr, ll pos, ll val) {
        if (tl == tr) {
            t[v] = val;
        } else {
            ll tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, val);

            t[v] = functionValue(t[v * 2], t[v * 2 + 1]);
        }
    }
};


int main() {
    FAST_IO
    ll n, m, k;
    cin >> n >> m >> k;

    ll a[n+1]; ll b[m+1];
    a[0] = 0; b[0] = 0;
    rep(i, n){
        cin>>a[i+1];
        a[i+1]+=a[i];
    }
    rep(i, m){
        cin>>b[i+1];
        b[i+1]+= b[i];
    }
    ll j = m; ll ans = 0;
    rep(i, n+1){
        if(a[i]>k){
            break;
        }
        while(b[j]>k-a[i]){
            j--;
        }
        ans = max(ans, i+j);
    }cout<<ans;
    return 0;
}
