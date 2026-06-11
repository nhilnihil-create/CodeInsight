#include <bits/stdc++.h>
using namespace std;
#define arep(i, x, n) for (int i = int(x); i < (int)(n); i++)
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9 + 7
using ll = long long;

int main() {
    ll n;
    ll k;
    cin >> k >> n;
    vector<ll> a(n);
    rep(i, n){
        cin >> a[i];
    }

    ll temp = a[0] + (k - a[n-1]);
    arep(i, 1, n){
        ll temp2 = a[i] - a[i - 1];

        if(temp < temp2){
            temp = temp2;
        }
    }

    ll dist = k - temp;
    cout << dist << endl;
}