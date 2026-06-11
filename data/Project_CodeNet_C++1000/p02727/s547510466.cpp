#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<vector<int>> Graph;

int main() {
    int x,y,a,b,c;
    cin >> x >> y >> a >> b >> c;
    vector<int> eat(3,0);
    vector<ll> p(a),q(b),r(c);
    vector<pair<ll,int>> s; 
    rep(i,a) cin >> p[i]; sort(ALL(p));
    rep(i,b) cin >> q[i]; sort(ALL(q));
    rep(i,c) cin >> r[i]; sort(ALL(r));
    rep(i,x) s.push_back(make_pair(p[a-1-i],1));
    rep(i,y) s.push_back(make_pair(q[b-1-i],2));
    rep(i,c) s.push_back(make_pair(r[i],0));
    sort(ALL(s));
    ll ans=0;
    int j = x + y + c -1;
    while(eat[0]<x+y){
        if(s[j].second==1&&eat[1]<x){
            eat[1]++;
            eat[0]++;
            ans += s[j].first;
        } else if (s[j].second==2&&eat[2]<y){
            eat[2]++;
            eat[0]++;
            ans += s[j].first;
        } else {
            eat[0]++;
            ans += s[j].first;
        }
        j--;
    }
    cout << ans << endl;
}