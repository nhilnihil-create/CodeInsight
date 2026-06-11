#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;


int main() {
    ll a, b;
    cin >> a >> b;
    ll gcd = __gcd(a, b);
    ll ans = 0;
    for(int i = 2; i <= sqrt(gcd); ++i){
        if(gcd%i==0){
            ans++;
            while(gcd%i==0) {
                gcd/=i;
            }
        }
    }
    ans++;
    if(gcd!=1) ans++;
    cout << ans << endl;
    return 0;
}