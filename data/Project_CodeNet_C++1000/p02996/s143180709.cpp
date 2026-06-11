#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    ll n; cin >> n;
    V<P<ll, ll> > v(n);
    for(int i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        v[i] = make_pair(b, a);
    }

    sort(ALL(v));
    ll t = 0;
    for(int i = 0; i < n; i++){
        t += v[i].second;
        if(t <= v[i].first) continue;
        else{
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
