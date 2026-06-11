#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using P = pair<int,int>;
using ll = long long;
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.rbegin(),a.rend());
    ll sum = a[0];
    for (int i=1; i<n/2 ; i++) {
        sum += 2*a[i];
    }
    if (n%2 == 1) sum += a[n/2];
    cout << sum << endl;
    return 0;
}