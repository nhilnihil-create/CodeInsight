#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

ll gcd(ll a, ll b) {
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

ll lcm(ll a, ll b){
    return a*b / gcd(a, b);
}


int main() {

    ll a,b,c,d,m; cin >> a >> b >> c >> d;
    m = lcm(c,d);
    ll n[3];


    n[0] = (b/c)-((a-1)/c); //3
    n[1] = (b/d)-((a-1)/d); //2
    n[2] = (b/m)-((a-1)/m); //1

    cout << (b-a+1-n[0]-n[1]+n[2]);
    return 0;
}









