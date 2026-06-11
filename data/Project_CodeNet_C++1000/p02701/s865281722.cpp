#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mx = 10000007;
const ll mod = 1e9 + 7;
const double pi = acos(-1);
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) ((a) / __gcd((a), (b)) * (b))
#define FIO ios_base::sync_with_stdio(false);  cin.tie(NULL);

int main() {
    ll n;
    cin >> n;
    set<string>s;
    for (ll i = 0; i < n; i++) {
        string x;
        cin >> x;
        s.insert(x);

    }
    cout << s.size() << endl;
}
