#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
 
int main(void){
    ll n, a, b;
    cin >> n >> a >> b;
    ll d = n / (a + b);
    ll ans = d * a + min(n - (d * (a + b)), a);
    cout << ans << endl;
    return 0;
}