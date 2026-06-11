#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
void Main()
{
    ll K;
    cin >> K;

    queue<ll> que;
    repi(i, 10) que.push(i);

    ll cnt = 0;
    while (true) {
        ll v = que.front();
        que.pop();
        cnt++;
        if (cnt == K) {
            put(v);
            return;
        }

        ll m = v % 10;
        if (m != 0) que.push(10 * v + m - 1);
        que.push(10 * v + m);
        if (m != 9) que.push(10 * v + m + 1);
    }

}
signed main(){ Main();return 0;}