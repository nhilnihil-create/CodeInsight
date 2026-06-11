#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(),(c).end()
#define RALL(c) (c).rbegin(),(c).rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const ll INF = 1e18 + 10;

ll A, B, C, D;
ll num(ll n, ll c, ll d) {
    ll G = __gcd(c,d);
    ll L = c / G *d;
    return n - n/c - n/d + n/L;
}

int main() {
    cin >> A >> B >> C >> D;
    cout << num(B,C,D) - num(A-1,C,D) << endl;
}