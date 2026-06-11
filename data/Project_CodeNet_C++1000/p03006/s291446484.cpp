#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, ans=0, tmp=0;
vector<pair<ll, ll>> XY;
map<pair<ll, ll>, ll> M;

signed main(){
    cin >> N;
    for(int i=0;i<N;i++) {
        ll x, y;
        cin >> x >> y;
        XY.push_back(make_pair(x, y));
    }
    sort(XY.begin(), XY.end());
    for(int i=0;i<N-1;i++) {
        for(int j=i+1;j<N;j++) {            
            ll dx = XY[j].first-XY[i].first;
            ll dy = XY[j].second-XY[i].second;
            M[make_pair(dx, dy)]++;
        }
    }
    for(map<pair<ll, ll>, ll>::iterator itr=M.begin();itr!=M.end();itr++) {
        pair<pair<ll, ll>, ll> tmp = *itr;
        ans = max(ans, tmp.second);
    }
    cout << N-ans << endl;
    return 0;
}