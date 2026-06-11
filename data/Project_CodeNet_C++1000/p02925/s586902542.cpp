#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define rrep(i,n) for(int i=int(n-1);i>=0;i--)
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long;
using P = pair<int, int>;
using lP = pair<ll, ll>;
using fP = pair<double, double>;
using PPI = pair<P, int>;
ll const mod = 998244353;
//ll const mod=1e9+7;
const ll MAX = 300000;
using vi = vector<int>;
using vl = vector<ll>;
using vc = vector<char>;
using vd = vector<double>;
using vs = vector<string>;
using vp = vector<P>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvc = vector<vector<char>>;
using vvp = vector<vector<P>>;
using vvb = vector<vector<bool>>;
template <typename T>
bool chmax(T& a, const T b) { if (a < b) { a = b; return true; } return false; }
template <typename T>
bool chmin(T& a, const T b) { if (a > b) { a = b; return true; } return false; }


//////////////////////////////////////


int main() {
    int n;
    cin >> n;
    vvi a(n, vi(n));
    rep(i, n) {
        rep(j, n - 1) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    rep(i, n)a[i][n - 1] = INF;
    vp q;
    vvi used(n, vi(n));
    vi index(n);
    auto get_game = [&](int y) {
        int my_x = index[y];
        
        int opo = a[y][my_x];
        int opo_x = index[opo];
        if (a[opo][opo_x] == y) {
            if (y > opo)swap(y, opo);
            if (used[y][opo])return;
            q.push_back(P(y, opo));
            used[y][opo] = 1;
            
        }
    };
    rep(i, n) {
        get_game(i);
    }
    
    int ans = 0;
    while (q.size()) {
        vp prev;
        q.erase(unique(all(q)), q.end());
        swap(q, prev);
        for (auto x : prev) {
            if(index[x.fs]<n-2)index[x.fs]++;
            if(index[x.sc]<n-2)index[x.sc]++;
        }
        for (auto x : prev) {

            get_game(x.fs);
            get_game(x.sc);
        }
        
        ans++;
    }
    rep(i,n){
      if(index[i]!=n-2){
        cout<<-1<<endl;
        return 0;
      }
    }
    cout << ans << endl;

    return 0;
}