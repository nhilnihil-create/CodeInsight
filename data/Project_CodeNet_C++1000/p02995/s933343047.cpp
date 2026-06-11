#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;
typedef long long ll;


ll gcd(ll a, ll b){
    if (a < b) swap(a,b);
    if (a % b == 0) return b;
    return gcd(a % b, b);
}
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}
ll countNonDivisor(ll x, ll c, ll d){
    return x - x/c -x/d + x/lcm(c, d);
}
int main(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll upper = countNonDivisor(b, c, d);
    ll lower =countNonDivisor(a-1, c, d);

    cout << upper - lower  << endl;
}
