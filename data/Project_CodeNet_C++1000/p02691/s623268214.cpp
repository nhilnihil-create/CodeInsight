#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
   ll n; cin >> n;
   vector<ll> data(n);
   map<ll,ll> mapdata;
    rep(i,n){
        cin >> data[i];
        mapdata[data[i]+(i+1)]++;
    }
    ll ans = 0;
    rep(i,n) ans += mapdata[(i+1)-data[i]];
    cout << ans << endl;
}