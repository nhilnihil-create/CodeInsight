#include <bits/stdc++.h>
#include <cstdlib>  //abs()で絶対値を取得する（整数）
#include <cmath>    //abs()かfabs()で絶対値を取得する（少数）
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
int main(){
    ll n;
    ll a;
    ll b;
    ll x = 0;
    ll y = 0;
    ll ans = 0;
    cin >> n >> a >> b;
    x = n % (a+b);
    y = n / (a+b);
    if (x > a){
        ans = y * a + a;
    }
    if (x <= a){
        ans = y * a + x;
    }
    cout << ans;
    return 0;
}