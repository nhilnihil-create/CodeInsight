#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    ll a, b;
    cin >> a >> b;
    
    ll g = gcd(a,b);
    //cout << g << endl;
    
    ll ans = 0;
    for(ll i = 2; i*i <= g; i++) {
        if(g % i == 0) {
            ans++;
            while(g % i == 0) {
                g /= i;
            }
        }
    }
    
    if(g != 1)
        ans++;
    
    cout << ans+1 << endl;
    
    
    return 0;
}


