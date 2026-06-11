#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = 0;
    if(a == 0){
        cout << 0 << endl;
        return 0;
    }
    if(b == 0){
        cout << n << endl;
        return 0;
    }
    ans += n/(a+b)*a;
    n %= a+b;
    ans += min(n, a);
    cout << ans << endl;
}