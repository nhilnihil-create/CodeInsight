#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    ll m = 1000;
    ll n;
    cin >> n;
    vector<ll> a(87);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n - 1; i++){
        ll s = 0;
        if(a[i] < a[i + 1]) s = m/a[i];
        m += (a[i + 1] - a[i])*s;
    }

    cout << m << endl;
    
    return 0;
}