#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    ll sum = 0;
    rep(i,n) sum += a[i];
    vector<ll> x(n);
    x[0] = sum;
    int t = 1;
    rep(i,n/2){
        x[0] -= 2*a[t];
        t += 2;
    }
    rep(i,n-1){
        x[i+1] = 2*a[i] - x[i];
    }
    rep(i,n) cout << x[i] << ' ';
}