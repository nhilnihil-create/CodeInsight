#include "bits/stdc++.h"

using namespace std;

using ll = long long;

#define all(x) begin(x), end(x)
#define rot(s, k) rotate(s.begin(), s.begin()+ s.size()-(k%s.size()), s.end()); 

int main(){
ios_base::sync_with_stdio(0); cin.tie(0);
ll n,m; cin >> n >> m;
// tekler icin
// sadece m'i hesaplayabiliriz
ll ans = 0;
ans += (n-1)*(n)/2;
ans += (m-1)*(m)/2;
cout << ans << "\n";

}
