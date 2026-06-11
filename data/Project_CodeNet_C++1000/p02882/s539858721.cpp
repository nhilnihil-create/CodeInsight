//
// author  : Abhishek
//
#include <bits/stdc++.h>

#define ll long long
#define db double
#define deb(x) cout<<#x<<": "<<x<<"\n"
#define all(x) x.begin(),x.end()
#define fo(i, n) for(i=0 ; i<n ; i++)
#define Fo(i, k, n) for(i=k ; i<n ; i++)

using namespace std;

const ll mod = 1000000007;
const ll N = 300005;  // array size
const ll inf = 10000000000000000;


void print(vector<ll> v) {
    ll i;
    fo(i, v.size())cout << v[i] << " ";
    cout << "\n";
}

vector<ll> read(ll n) {
    ll i;
    vector<ll> arr(n, 0);
    fo(i, n)cin >> arr[i];
    return arr;
}

vector<ll> read(ll n, ll k) {
    ll i;
    vector<ll> arr(n + k, 0);
    Fo(i, k, n + k)cin >> arr[i];
    return arr;
}

bool isEven(ll n) {
    return n % 2 == 0;
}

bool isOdd(ll n) {
    return n % 2 != 0;
}


void solve() {
    ll t;
    cin >> (t);
    while (t--) {

        ll i, j, k, n, m, p, q, x, y, a, b, l, r;


    }
}

const db pi = 3.141592653589793238;

int main() {

//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j, k, n, m, p, q, l, r;

    db a, b, x, A, y;

    cin >> a >> b >> x;

    A = a * b * (0.5);
    y = x / a;

    db ans;

    if (y <= A) {

        ans = atan((2 * x) / (a * b * b));
        db val = (ans * 180) / pi;
        cout << fixed << setprecision(9) << (db)90- val;
    } else {

        ans = atan((a) / (2 * b - ((2 * x) / (a * a))));
        db val = (ans * 180) / pi;
        cout << fixed << setprecision(9) << (db)90 - val;
    }


    return 0;
}


