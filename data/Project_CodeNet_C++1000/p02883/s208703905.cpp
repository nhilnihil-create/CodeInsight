#include <bits/stdc++.h>
#define pii pair<int, pair<int, int>>
#define ss second
#define ff first
#define all(x) ((x).begin(), (x).end())

using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
const ll oo = 1e14;
const double PI = 3.14159265;

int main(){
    ios_base::sync_with_stdio(false);
    ll n, k, l = -1, r = 0;
    cin >> n >> k;

    vector<ll> a(n), f(n);

    for (auto& x : a) cin >> x;
    for (auto& x : f) cin >> x;

    sort(a.begin(), a.end());
    sort(f.begin(), f.end());
    reverse(f.begin(), f.end());

    for (int i=0; i<n; i++) {
        r = max(r, f[i]*a[i]);
        //cout << a[i] << " " << f[i] << endl;
    }
    r++;

    while (l < r- 1){
        ll mid = (l+r)/2, tot = 0;
        

        for (int i=0; i<n; i++){
            if (a[i]*f[i] > mid) tot+= a[i] - mid/f[i];
        }

        if (tot <= k){
            r = mid;
        }
        else {
            l = mid;
        }
    }

    cout << r << endl;

    return 0;
}