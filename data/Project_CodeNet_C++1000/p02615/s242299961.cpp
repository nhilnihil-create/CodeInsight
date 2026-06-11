#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i, n) for (ll i = 0; i < ll(n); i++)
#define REPD(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i < ll(b); i++)
#define FORD(i, a, b) for (ll i = b - 1; i >= ll(a); i--)
#define WRAP(y, x, h, w) (0 <= y && y < h && 0 <= x && x < w)

#define ALL(x) (x).begin(), (x).end()

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    int N;
    cin >> N;
    vector<ll> v(N);
    REP(i, N)
    cin >> v[i];
    sort(ALL(v), greater<ll>());
    ll ans = v[0];
    queue<ll> q;
    q.push(v[1]);
    q.push(v[1]);
    FOR(i,2, N){
        ans+=q.front();
        q.pop();
        q.push(v[i]);
        q.push(v[i]);
    }
    cout << ans << endl;
}