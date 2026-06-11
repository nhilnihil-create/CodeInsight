#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const ll mod = 1000000007;

ll calcA(vector<ll> a, int n) {
    ll res = (a[n-1]+a[n-3]) % mod;
    return res;
}

int main(void){
    int s;
    cin >> s;

    vector<ll> a(s+1);
    a[0] = 1;
    a[1] = a[2] = 0;

    for (int i = 3; i <= s; i++) {
        a[i] = calcA(a, i);
    }
    cout << a[s] << endl;
    return 0;
}
