#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define PI 3.14159265358979323846264338327950L
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;
int main(void){
    // Your code here!
    ll n, m;
    cin >> n >> m;
    vector<int> a(m);
    ll ans= 0;
    rep(i, m){cin >> a[i]; ans += a[i];}
    if(ans > n){cout << -1;}
    else{cout << n-ans;}
    return 0;
}