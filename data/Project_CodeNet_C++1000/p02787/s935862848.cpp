//
// author  : Abhishek
//
#include <bits/stdc++.h>
#include<chrono>

#define ll long long
#define db double
#define deb(x) cout<<#x<<": "<<x<<"\n"
#define all(x) x.begin(),x.end()
#define fo(i, n) for(i=0 ; i<n ; i++)
#define Fo(i, k, n) for(i=k ; i<n ; i++)

using namespace std;
using namespace chrono;

const ll MOD = 1000000007;
const ll N = 3005;  // array size
const ll inf = 10000000000000000;


void print(vector<ll> v) {
    ll i;
    fo(i, v.size())cout << v[i] << " ";
    cout << "\n";
}

void print(vector<pair<ll, ll> > v) {
    ll i;
    fo(i, v.size()) {
        cout << v[i].first << " " << v[i].second << "\n";
    }
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

int dp[10010][1010];
ll h, n;
vector<ll> a(N), b(N);

ll get(ll health, ll pos) {

    if (pos == n) {
        return INT_MAX;
    }

    if (health <= 0) {
        return 0;
    }

    if (dp[health][pos] != -1) {
        return dp[health][pos];
    }

    // take pos
    ll op1 = b[pos] + get(health - a[pos], pos);
    ll op2 = get(health, pos + 1);

    dp[health][pos] = min(op1, op2);
    return dp[health][pos];
}

void solve() {
    ll t = 1;
//    cin >> (t);
    while (t--) {

        ll i, j, k, m, p, q, x, y, l, r;
        cin >> h >> n;

        fo(i, n) {
            cin >> a[i] >> b[i];
        }

        fo(i, h + 1) {
            fo(j, n + 1) {
                dp[i][j] = -1;
            }
        }

//        fo(i, h) {
//            fo(j, n) {
//                cout << dp[i][j] << " ";
//            }
//            cout << "\n";
//        }

        ll ans = get(h, 0);

        cout << ans;

    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    auto start = high_resolution_clock::now();

    solve();

    ll i, j, k, n, m, p, q, x, y, a, b, l, r;


    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
#ifndef ONLINE_JUDGE
    cerr << "Time: " << duration.count() / 1000.0 << endl;
#endif


    return 0;
}


