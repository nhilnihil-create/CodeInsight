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

int main()
{   
    int n, x, y;
    cin >> n >> x >> y;
    --x, --y;
    vvi g(n);
    rep(i, n-1) {
        g[i].push_back(i+1);
        g[i+1].push_back(i);
    }
    g[x].push_back(y); g[y].push_back(x);

    vvi dist(n, vi(n, 114514));
    rep(i, n) {
        queue<P> q;
        q.push({i, 0});
        while(!q.empty()) {
            auto x = q.front(); q.pop();
            int p = x.first, s = x.second;

            for(int j : g[p]) {
                if(dist[i][j] != 114514) continue;
                q.push({j, s+1});
                dist[i][j] = s+1;
            }
        }
    }

    map<int, int> m;
    rep(i, n) for(int j = i+1; j < n; j++) m[dist[i][j]]++;
    for(int i = 1; i <= n-1; i++) cout << m[i] << endl;
        
    return 0;
}
