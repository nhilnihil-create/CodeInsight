#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    ll n, k;
    cin >> n >> k;
    unordered_set<ll> visited;
    visited.emplace(n);
    ll m = 1e18;
    while(true){
        if (n >= k * 2) {
            n -= n / k * k;
        }
        n = abs(n - k);
        m = min(m, n);
        if (visited.count(n) >= 1) {
            put(m);
            return 0;
        }
        visited.emplace(n);
    }



    return 0;
}