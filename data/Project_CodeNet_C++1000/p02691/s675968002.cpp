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
   int n; cin >> n;
   vector<ll> data(n);
   map<ll,ll> map1, map2;
    rep(i,n){
        cin >> data[i];
        map1[(i+1)+data[i]]++;
        map2[(i+1)-data[i]]++;
    }
    ll ans = 0;
    loop(i,1,n+1) if(map1[i]>0 && map2[i]>0) ans += map1[i]*map2[i];
    cout << ans << endl;
}

