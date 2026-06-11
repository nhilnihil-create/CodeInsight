#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define PI 3.14159265358979323846264338327950L
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;
int main(void){
    // Your code here!
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans= 0;
    ll frac = n / (a + b);
    ll frac2 = n % (a + b);
    ans = frac*a;
    if(frac2 > 0){
        if(frac2 < a){
            ans += frac2;
        }
        if(frac2 >= a){
            ans += a;
        }
    }
    cout << ans << endl;
    return 0;
}
