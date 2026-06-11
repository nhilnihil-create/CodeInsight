#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pil = pair<pii,int>;

int main(){
    int s,t,m;
    cin >> s >> t >> m;
    vector<int> a(s);
    rep(i,s) cin >> a[i];
    vector<int> b(t);
    rep(i,t) cin >> b[i];
    vector<pil> q(m);
    rep(i,m){
        int x,y,z;
        cin >> x >> y >> z;
        q[i].first.first = x;
        q[i].first.second = y;
        q[i].second = z;
    }
    int r = 2e9;
    rep(i,m){
        int s = a[q[i].first.first-1] + b[q[i].first.second-1] - q[i].second;
        r = min(r,s);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    r = min(r,(a[0]+b[0]));
    cout << r << endl;
}
