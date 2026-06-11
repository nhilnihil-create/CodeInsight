#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1; 
   // cin >> t;
    for(ll T = 0; T < t ; T++){
        ll n, ans = 0;
        cin >> n;
        if(n%2 == 0){
            n /= 10;
            ans += n;
            while(n){
                n /= 5;
                ans += n;
            }
        }
        cout << ans << endl;
    }
    return 0;
}