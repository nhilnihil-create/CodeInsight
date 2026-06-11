#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    string L;
    cin >> L;
    ll len = L.size();
    ll ans;
    vector<ll> dp1(len + 1, 0);
    vector<ll> dp2(len + 1, 0);
    dp1[1] = 2;
    dp2[1] = 1;
    for (ll i = 1; i < len; i++){
        if (L[i] == '0'){
            dp1[i + 1] = dp1[i];
            dp2[i + 1] = (dp2[i] * 3) % 1000000007;
        }
        else{
            dp1[i + 1] = (dp1[i] * 2) % 1000000007;
            dp2[i + 1] = (dp1[i] + dp2[i] * 3) % 1000000007;
        }
    }
    ans = (dp1[len] + dp2[len]) % 1000000007;
    cout << ans << endl;
}