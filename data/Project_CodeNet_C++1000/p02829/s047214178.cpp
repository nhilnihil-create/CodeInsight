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

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    auto start = high_resolution_clock::now();

    ll i, j, k, n, m, p, q, x, y, a, b, l, r;

    cin >> x >> y;

    vector<ll> done(3, 0);
    done[x - 1] = 1;
    done[y - 1] = 1;

    fo(i, 3) {
        if (!done[i]) {
            cout << i + 1;
            break;
        }
//        break;
    }


    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
#ifndef ONLINE_JUDGE
    cerr << "Time: " << duration.count() / 1000.0 << endl;
#endif


    return 0;
}


