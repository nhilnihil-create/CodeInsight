#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    ll n;
    cin >> n;
    ll sum = 0;
    vector<ll> a(n);
    rep(i,n){ 
        cin >> a[i];
        sum += a[i];
    }
    ll minx = sum ,s = 0;
    rep(i,n){
        s += a[i];
        minx = min(minx,abs(s - (sum - s)));
    }
    cout << minx << endl;
}