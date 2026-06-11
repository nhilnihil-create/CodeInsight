#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i,n); for(long long i = 0;i < (n);i++)
using ll = long long;
using P = pair<long long,long long>;
template <class T> using vec = vector<T>;

ll gcd(ll a,ll b){return b == 0 ? a : gcd(b,a%b);}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a,b,c,d,e; cin >> a >> b >> c >> d; e = lcm(c,d);
    cout << (b - a + 1) - (b/c - a/c + (a%c == 0 ? 1 : 0)) - (b/d - a/d + (a%d == 0 ? 1 : 0)) + (b/e - a/e + (a%e == 0 ? 1 : 0)) << endl;
}