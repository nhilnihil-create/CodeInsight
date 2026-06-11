#include <bits/stdc++.h>


using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;

ll modulo(ll a, ll m){
    return (a + m)%m;
}

int main (){
    ll n, k, x, ans = 0;
    cin >> n >> k;

    vector<ll> ps(n+1);
    ps[0] = 0;

    for (int i=0; i<n; i++) cin >> x , ps[i+1] = ps[i]+x;

    map<int, int> hist;
    hist[0]++;
    for (int i=1; i<n+1; i++){
        if(i >= k ) hist[modulo(ps[i-k] - (i-k), k)]--;
        ans += hist[modulo(ps[i] - i, k)];
        hist[modulo(ps[i] - i, k)]++;
    }
    cout << ans << endl;
    return 0;
}