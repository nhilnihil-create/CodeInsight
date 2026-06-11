#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define LCM(a, b) (a) / __gcd((a), (b)) * (b)
#define CEIL(a, b) (a)/(b)+(((a)%(b))?1:0)
#define ln '\n'

using namespace std;
using LL = long long;
using ldouble = long double;
using P = pair<int, int>;
using LP = pair<LL, LL>;

static const int INF = INT_MAX;
static const LL LINF = LLONG_MAX;
static const int MIN = INT_MIN;
static const LL LMIN = LLONG_MIN;
static const int MOD = 1e9 + 7;
static const int SIZE = 200005;

const int dx[] = {0, -1, 1, 0};
const int dy[] = {-1, 0, 0, 1};

vector<LL> Div(LL n) {
    vector<LL> ret;
    for(LL i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            ret.pb(i);
            if(i * i != n) ret.pb(n / i);
        }
    }
    sort(all(ret));
    return ret;
}

class Node {
public:
    int next;
    long long cost;

    Node(int nxt, int cst) {
        next = nxt;
        cost = cst;
    }

    Node(int nxt) {
        next = nxt;
        cost = 0;
    }
};

class Tree {
public:
    vector<Node> tree[SIZE];
    int root;

    Tree() {
        root = 1;
    }

    Tree(int rt) {
        root = rt;
    }

    void insert(int u, int v) {
        tree[u].push_back(Node(v, 0ll));
        tree[v].push_back(Node(u, 0ll));
    }

    void insert(int u, int v, long long cost) {
        tree[u].push_back(Node(v, cost));
        tree[v].push_back(Node(u, cost));
    }

    int size(int u) {
        return tree[u].size();
    }

    Node getNode(int u, int idx) {
        return tree[u][idx];
    }

    long long getCost(int u, int idx) {
        return tree[u][idx].cost;
    }

    int getNext(int u, int idx) {
        return tree[u][idx].next;
    }

    void setRoot(int rt) {
        root = rt;
    }

};

void dfs(int cur, LL cnt);

LL counter[SIZE];
bool isvisit[SIZE];
Tree tree;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    tree.setRoot(1);

    for(int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        tree.insert(a, b);
    }

    while(Q--) {
        int p, x;
        cin >> p >> x;
        counter[p] += x;
    }

    dfs(1, 0ll);

    for(int i = 1; i <= N; ++i) {
        cout << counter[i] << " ";
    }
    cout << endl;

    return 0;
}

void dfs(int cur, LL cnt) {
    if(isvisit[cur]) return;
    isvisit[cur] = true;

    counter[cur] += cnt;
    cnt = counter[cur];

    for(int i = 0; i < tree.size(cur); ++i) {
        dfs(tree.getNext(cur, i), cnt);
    }

    return;
}
