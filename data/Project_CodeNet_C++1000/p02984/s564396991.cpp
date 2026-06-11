#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    ll a[n];
    ll as=0;
    ll at=0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        as+=a[i];
        if(i%2==0)at+=a[i];
    }
    ll x[n];
    x[0]=at-as/2;
    for(int i = 1; i < n; i++) {
        x[i]=a[i-1]-x[i-1];
    }

    for(int i = 0; i < n; i++) {
        cout << x[i]*2 << " ";
    }
    cout << "\n";

    return 0;
}