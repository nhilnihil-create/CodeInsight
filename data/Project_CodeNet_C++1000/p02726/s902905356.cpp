#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<double> vd;
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

int main()
{   
    int n, x, y;
    cin >> n >> x >> y;
    --x, --y;
    vvi g(n);
    g[x].push_back(y); g[y].push_back(x);
    rep(i, n-1) {
        g[i].push_back(i+1), g[i+1].push_back(i);
    }

    vvi d(n, vi(n, -1));
    queue<P> q;
    rep(i, n) {
        q.push({i, 0});
        while(!q.empty()) {
            auto x = q.front(); q.pop();
            int p = x.first, s = x.second;
            for(int u : g[p]) {
                if(d[i][u] != -1) continue;
                d[i][u] = s+1;
                q.push({u, s+1});
            }
        }
    }

    vi ans(n);
    rep(i, n) for(int j=i+1; j < n; j++) {
        ans[d[i][j]-1]++;
    }

    rep(i, n-1) cout << ans[i] << endl;

    return 0;
}
