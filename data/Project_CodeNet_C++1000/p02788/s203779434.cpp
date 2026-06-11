#include <iostream>
#include <map>

using namespace std;
map<int,int> mp,ind;
typedef long long ll;
int imos[400010] = {};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,d,a;
    cin >> n >> d >> a;
    for(i=0;i<n;i++){
        int x,h; cin >> x >> h;
        mp[x] += h; mp[x + 2*d + 1] += 0;
    }
    int now = 0;
    for(auto x:mp){
        ind[x.first] = now; now++;
    }
    ll ans = 0; int dm = 0;
    for(auto x:mp){
        dm += imos[ind[x.first]];
        if(x.second<=dm) continue;
        int t = (x.second - dm + a - 1)/a;
        ans += t; dm += a*t;
        imos[ind[x.first + 2*d + 1]] -= a*t;
    }
    cout << ans << endl;
}