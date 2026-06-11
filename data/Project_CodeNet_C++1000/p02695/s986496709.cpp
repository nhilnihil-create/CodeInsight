#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

void YN(bool flg){if(flg) cout << "YES" << endl; else cout << "NO" << endl;}
void Yn(bool flg){if(flg) cout << "Yes" << endl; else cout << "No" << endl;}
void yn(bool flg){if(flg) cout << "yes" << endl; else cout << "no" << endl;}

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n, m, q, ans = 0;
vi a, b, c, d;

void calc(vi v) {
    int sum = 0;
    rep(i, q) if(v[b[i]] - v[a[i]] == c[i]) sum += d[i];
    ans = max(ans, sum);
}

void func(int prev, int depth, vi v) {
    if(depth == n) {
        calc(v);
        return;
    }

    for(int add = prev; add <= m; add++) {
        v.push_back(add);
        func(add, depth+1, v);
        v.pop_back();
    }
}

int main()
{   
    cin >> n >> m >> q;
    a.resize(q), b.reserve(q), c.resize(q), d.resize(q);
    rep(i, q) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        --a[i], --b[i];
    }

    vi v;
    func(1, 0, v);
    
    cout << ans << endl;

    return 0;
}
