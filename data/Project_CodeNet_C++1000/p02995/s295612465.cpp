#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

ll gcd(ll a, ll b){
    if(a < b) return gcd(b, a);
    ll r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

ll lcm(ll a, ll b){
    ll ret = a / gcd(a,b) * b;
    return ret;
}

int main(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll numc = (b / c) - ((a + c - 1) / c) + 1;
    ll numd = (b / d) - ((a + d - 1) / d) + 1;
    ll l = lcm(c, d);
    ll numl = (b / l) - ((a + l - 1) / l) + 1;
    cout << b - a + 1 - numc - numd + numl << endl;
    return 0;
}