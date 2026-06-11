
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

ll gcd(ll x, ll y){
    if(y==0) return x;
    else return gcd(y,x%y);
}
ll lcm(ll x, ll y){
    //掛け算をする前に割り算をすることでx*yがllに治らない場合をケアしている
    return x/gcd(x,y)*y;
}
ll f(ll x, ll c, ll d){
    ll res = x;
    res -= x/c;
    res -= x/d;
    res += x/lcm(c,d);
    return res;
}

//f(x) x以下でcでもdでも割り切れない数　を用意すると
//f(b)-f(a)が求めたい数になる
//f(x)=x-x/c-x/d+x/(c*d)
int main(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll commoncd = lcm(c,d);
    ll ans = f(b,c,d) - f(a-1,c,d);
    cout << ans << endl;
    return 0;
}