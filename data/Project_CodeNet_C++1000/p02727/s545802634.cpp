#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 100010;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}

/*------------------------------------------------------------------*/
int main(){
    ll x, y, a, b, c; cin >> x >> y >> a >> b >> c;
    vector<ll> p(a);
    rep(i, a) cin >> p[i];
    vector<ll> q(b);
    rep(i, b) cin >> q[i];
    vector<ll> r(c);
    rep(i, c) cin >> r[i];
    sort(p.begin(), p.end(), greater<>());
    sort(q.begin(), q.end(), greater<>());
    vector<ll> apple;
    rep(i, x) apple.push_back(p[i]);
    rep(i, y) apple.push_back(q[i]);
    rep(i, c) apple.push_back(r[i]);
    sort(apple.begin(), apple.end(), greater<>());
    ll sum = 0;
    rep(i, x + y) sum += apple[i];
    cout << sum << endl;
}