#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,d;
    cin >> n >> d;
    vector<ll> x(n);
    vector<ll> y(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    int cnt=0;
    for(int i = 0; i < n; i++) {
        if(d*d>=(x[i]*x[i]+y[i]*y[i])) cnt++;
    }
    cout << cnt << "\n";
    return 0;
}