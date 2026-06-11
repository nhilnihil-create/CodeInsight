#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; i++)
using p = pair<int,int>;
int main(){
    int h,w;
    long long m;
    cin >> h >> w >> m;
    vector <int> xx(h);
    vector <int> yy(w);
    set <p> s;
    rep(i,m){
        int x,y;
        cin >> x >> y;
        --x; --y;
        xx[x] += 1;
        yy[y] += 1;
        s.emplace (x,y);
    }
    int mx = 0;
    int my = 0;
    rep(i,h) mx = max(mx,xx[i]);
    rep(i,w) my = max(my, yy[i]);
    int ans = mx + my;
    vector<int> xm,ym;
    rep(i,h){
        if (xx[i] == mx) xm.push_back(i);
    }
    rep(i,w){
        if (yy[i] == my) ym.push_back(i);
    }
    for (int j : xm) for (int k : ym){
        if (s.find({j,k}) == s.end()){
            cout << ans << endl;
            return 0;
        }
    }
    ans -= 1;
    cout << ans << endl;
}