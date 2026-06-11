#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define debug(a) cout << "["; rep(i,a.size()) cout << a[i] << ", "; cout<<"]"<< endl;

const ll mod = 1000000007;

int main() {
    int h,w; cin >> h >> w;
    vector<vector<int>> hos(h+2,vector<int>(1,0));
    vector<vector<int>> wos(w+2,vector<int>(1,0));
    vector<string> grid(h);
    rep(i,h) cin >> grid.at(i);
    rep(i,h){
        rep(j,w){
            if(grid.at(i).at(j) == '#'){
                hos.at(i+1).push_back(j+1);
                wos.at(j+1).push_back(i+1);
            }
        }
    }
    rep(i,h){
        hos.at(i+1).push_back(w+1);
    }
    rep(i,w){
        wos.at(i+1).push_back(h+1);
    }
    
    int ans = 0;
    rep(i,h){
        rep(j,w){
            if(grid.at(i).at(j) == '.'){
                int cnt = 0;
                int hosi,wosi;
                hosi = lower_bound(hos.at(i+1).begin(), hos.at(i+1).end(), j+1) - hos.at(i+1).begin();
                cnt += hos.at(i+1).at(hosi) - hos.at(i+1).at(hosi - 1) - 1;
                wosi = lower_bound(wos.at(j+1).begin(), wos.at(j+1).end(), i+1) - wos.at(j+1).begin();
                cnt += wos.at(j+1).at(wosi) - wos.at(j+1).at(wosi - 1) - 1;
                cnt--;
                ans = max(ans, cnt);
            }
        }
    }
    cout << ans << endl;
    return 0;
}