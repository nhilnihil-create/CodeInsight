#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const int mod = 1000000007;
int main(){
    int n;
     cin >> n;
     vector<ll> a(n), b(n);
     rep(i,n){
        cin >> a[i];
        b[0] += a[i]*pow(-1,i%2);
    }
    rep(i,n-1){
        b[i+1] = 2*a[i]-b[i];
    }
    rep(i,n)cout << b[i] << endl;
    return 0;
}