#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;

template<typename T>
void print(const vector<T> &x) {
    int n = x.size();
    rep(i,n) {
        cout << x[i];
        if (i!=n-1) cout<<" ";
        else cout << endl;
    }
}

template<typename T>
void print(const vector<vector<T>> &x) {
    int n = x.size();
    rep(i,n) {
        rep(j,x[i].size()) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

template<typename T>
void print(const vector<T> &x, int n) {
    rep(i,n) {
        cout << x[i];
        if (i!=n-1) cout<<" ";
        else cout << endl;
    }
}

template<typename T>
void print(const vector<vector<T>> &x, int n, int m) {
    rep(i,n) {
        rep(j,m) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void input_init() {
    cin.tie(0); ios::sync_with_stdio(false);
}

class RMQ {
private:
    vector<ll> val;
    int N;
public:
    RMQ(int n, ll init);
    void update(int i, int x);
    ll find(int r, int l, int fn, int fr, int fl);
    ~RMQ();
};

RMQ::RMQ(int n, ll init) {
    N = n;
    val.resize(2*N-1, init);
}

void RMQ::update(int i, int x) {
    i += N-1;
    val[i] = x;
    while (i > 0) {
        i = (i-1)/2;
        val[i] = min(val[i*2+1], val[i*2+2]);
    }
}

ll RMQ::find(int a, int b, int k, int l, int r) {
    // [a, b)のクエリ
    // ノードk(区間[a, b)担当)が答える
    if (b <= l || r <= a) return LINF; // 区間がかぶらなければLINF
    if (a <= l && r <= b) return val[k]; // 区間が完全にかぶっていればval[k]
    else {
        // 一部だけかぶる場合は左右の子に委託する
        ll c1 = find(a, b, 2*k+1, l, (l+r)/2);
        ll c2 = find(a, b, 2*k+2, (l+r)/2, r);
        return min(c1, c2);
    }
}

RMQ::~RMQ() {
}

int main(int argc, char const *argv[]) {
    int n,m; cin>>n>>m;
    string s; cin>>s;
    int N = 1;
    while (N<(n+1)) N*=2;
    RMQ dp(N,INF);
    dp.update(n,0);
    vector<int> ans(n+1,INF);
    ans[n] = 0;
    for (int i = n-1; i >= 0; --i) {
        if (s[i]=='1') continue;
        int cost = dp.find(i, min(n+1,i+m+1),0,0,N)+1;
        dp.update(i,cost);
        ans[i] = cost;
    }
    // print(ans);
    if (ans[0]>=INF) {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> id;
    id.push_back(0);
    int x = ans[0];
    rep(i,n) {
        if (ans[i]!=ans[i+1] && x>ans[i+1]) {
            id.push_back(i+1);
            x = ans[i+1];
        }
    }
    // print(id);
    rep(i,id.size()-1) {
        cout << id[i+1]-id[i] << ' ';
    }
    cout << '\n';

    return 0;
}