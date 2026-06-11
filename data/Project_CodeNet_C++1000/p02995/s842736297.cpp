#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>
#define all(a) a.begin(),a.end()
template <typename T>
inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }

ll f(ll n, ll x){
    if(n>=0)
        return n/x + 1;
    else
        return 0;
}

int main(){
    ll a, b, c, d;
    cin >> a >> b>>c >> d;
    ll lcm = (c*d)/gcd(c,d);

    ll dc = f(b, c)-f(a-1, c);
    ll dd = f(b, d)-f(a-1, d);
    ll l = f(b, lcm)-f(a-1, lcm);

    cout << (b-a)-(dc+dd-l)+1;
}