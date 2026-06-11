#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll gcd(ll a,ll b){while(a&&b){if(a>b) a = a%b;else b = b%a;}return a+b;}
ll lcm(ll a,ll b){return a * b / gcd(a, b);}

int main()
{
    ll n, m; cin >> n >> m;
    vector<ll> a(n); for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] /= 2;
    }

    ll lc = 1;
    for(int i = 0; i < n; i++){
        lc = lcm(lc, a[i]);
        if(lc > m) {
            cout << 0 << endl;
            return 0;
        }
    }
    int lcnt = 0, lctmp = lc;
    while(lctmp % 2 == 0) {
        lctmp /= 2;
        lcnt++;
    }
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        while(a[i] % 2 == 0) {
            a[i] /= 2;
            cnt++;
        }
        if(cnt != lcnt) {
            cout << 0 << endl;
            return 0;
        }
    }

    cout << (m / lc) - (m / (lc * 2)) << endl;

}