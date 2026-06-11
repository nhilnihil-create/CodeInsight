#include <bits/stdc++.h>

#define ll long long
#define ii pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define pi 3.14159265
#define oo 1000000007
#define loo 0x7fffffffffffffff

#define prime 1000000007

#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << "\n";
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int h, w, m; cin >> h >> w >> m;
    int row[h], col[w];
    memset(row, 0, sizeof row);
    memset(col, 0, sizeof col);
    set<ii> yo;
    for (int i = 0; i < m; ++i){
        int x, y; cin >> x >> y;
        x--;
        y--;
        yo.insert({x, y});
        row[x]++;
        col[y]++;
    }
    int ma = 0, ans = 0;
    vi px, py;
    for (int i = 0; i < h; ++i){
        ma = max(row[i], ma);
    }
    for (int i = 0; i < h; ++i){
        if(row[i] == ma){
            px.pb(i);
        }
    }
    ans = ma;
    ma = 0;
    for (int i = 0; i < w; ++i){
        ma = max(col[i], ma);
    }
    for (int i = 0; i < w; ++i){
        if(col[i] == ma){
            for(auto l : px){
                if(yo.find({l, i}) == yo.end()) {
                    cout << ans+ma << "\n";
                    return 0;
                }
            }
        }
    }
    ans+=ma;

    cout << ans-1 << "\n";

    return 0;
}