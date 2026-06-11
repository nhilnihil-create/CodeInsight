#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
vector<ll> ans(2001,0);
 
int main(){
    ans.at(0) = 1;
    ll s; cin >> s;
    for(int i=3;i<=s;i++){
        ll x = 0;
        for(int j=0;j<=i-3;j++){
            x = (x+ans.at(j))%mod;
        }
      	ans.at(i)=x;
    }
    cout << ans.at(s);
    return 0;
}