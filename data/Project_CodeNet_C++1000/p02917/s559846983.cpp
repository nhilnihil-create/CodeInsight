#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mx = 10000007;
const ll mod = 1e9 + 7;
const double pi = acos(-1);
#define    ss   second
#define    ff   first
#define    pb   push_back
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) ((a) / __gcd((a), (b)) * (b))
#define FIO ios_base::sync_with_stdio(false);  cin.tie(NULL);


int main() {
    FIO;
    ll n;
    cin >> n;
    vector<ll>b(n-1);
    for (ll i = 0; i < n - 1; i++) {
        cin >> b[i];
    }

    vector<ll>a(n);
    a[0] = b[0];

    for (ll i = 1; i < n - 1; i++) {
        a[i] = min(b[i], b[i-1]);
    }

    a[n - 1] = b[n - 2];

    ll s = 0;

    for (ll i = 0; i < n ; i++) {
        s += a[i];
    }

    cout << s << endl;
    return 0;

}

