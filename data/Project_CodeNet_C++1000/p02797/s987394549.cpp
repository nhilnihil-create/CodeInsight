#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n,k,s;
    cin >> n >> k >> s;
    vector<ll>ans(n,s);
    for(ll i=k;i<n;i++){
        ans[i]--;
      if(s==1)ans[i]+=2;
    }
    for(ll i=0;i<n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}