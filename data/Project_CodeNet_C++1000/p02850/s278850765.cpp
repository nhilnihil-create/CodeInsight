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

void dfs(int pos, int per_color);

vector<int> tree[SIZE];
bool isvisit[SIZE];
map<P, int> mp;
int mx = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<P> edge;
    for(int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        tree[a].pb(b);
        tree[b].pb(a);
        if(a > b) swap(a, b);
        edge.pb(MP(a, b));
    }

    dfs(1, -1);
    set<int> st;
    for(int i = 0; i < N - 1; ++i) {
        st.insert(mp[MP(edge[i].F, edge[i].S)]);
    }

    cout << st.size() << endl;
    for(int i = 0; i < N - 1; ++i) {
        cout << mp[MP(edge[i].F, edge[i].S)] << endl;
    }

    return 0;
}

void dfs(int pos, int per_color) {
    if(isvisit[pos]) return;
    isvisit[pos] = true;

    int c = 1;
    for(int i = 0; i < tree[pos].size(); ++i) {
        if(isvisit[tree[pos][i]]) continue;
        if(c == per_color) ++c;
        int a, b;
        a = pos, b = tree[pos][i];
        if(a > b) swap(a, b);
        mp[MP(a, b)] = c;
        dfs(tree[pos][i], c);
        ++c;

    }
    return;
}

