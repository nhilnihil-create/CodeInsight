#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    ll op = a + b;
    ll ans;
    if(a == 0) ans = 0;
    else{
        if(n % op == 0) ans = n / op * a;
        else{
            if(n%op >= a) ans = n/op*a + a;
            else ans = n/op*a + n%op;
        }
    } 
    cout << ans << endl;
    return 0;
}