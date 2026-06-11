#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
const int mod =1'000'000'007;

ll factor(ll n, ll k){
    ll x = abs(n - k);
    if (x > n){
        return n;
    }
    return factor(x, k);
}

int main(){
    ll n, k;
    cin >> n >> k;
    if (n % k == 0){
        cout << 0 << endl;
        return 0;
    }
    ll x = n % k;
    ll y = abs(x - k);
    ll z = min(x, y);
    cout << z << endl;
    return 0;
}
