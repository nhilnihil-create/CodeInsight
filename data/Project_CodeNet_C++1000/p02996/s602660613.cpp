#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;


int main() {
    int n; cin >> n;
    V<ll> a(n), b(n);
    V<P<ll, ll> > ab(n);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        ab[i] = make_pair(b[i], a[i]);
        sum += a[i];
    }

    sort(ALL(b));
    if(b[n - 1] < sum){
        cout << "No" << endl;
        return 0;
    }

    sort(ALL(ab));
    ll suma = 0;
    for(int i = 0; i < n; i++){
        suma += ab[i].second;
        if(suma <= ab[i].first) continue;
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;

}
