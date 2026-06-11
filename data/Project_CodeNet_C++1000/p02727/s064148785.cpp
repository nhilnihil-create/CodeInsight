#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<pair<int, int>> d;
    rep(i, a){
        int p;
        cin >> p;
        d.pb({p, 0});
    }
    rep(i, b){
        int q;
        cin >> q;
        d.pb({q, 1});
    }
    rep(i, c){
        int r;
        cin >> r;
        d.pb({r, 2});
    }
    ll ans = 0;
    sort(d.begin(), d.end(), greater<pair<int, int>>());
    int s = 0, t = 0, u = 0;
    int i = 0;
    while(s + t + u < x + y){
        if (d[i].second == 0 && s < x){
            ans += (ll) d[i].first;
            s++;
        }
        if (d[i].second == 1 && t < y){
            ans += (ll) d[i].first;
            t++;
        }
        if (d[i].second == 2){
            ans += (ll) d[i].first;
            u++;
        }
        i++;
    }
    cout << ans << endl;
}