#include <bits/stdc++.h>
#define ll long long int
#define forr(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
#define oo 100000000000000000
using namespace std;



void _sol(){
    int n; cin >> n;
    vector<ll> v(n);
    for(auto &i: v) cin >> i;
    ll ans = 0;
    for(int i=1;i<n;i++){
        if(v[i] < v[i-1]){
            ans += v[i-1]  - v[i];
            v[i] = v[i-1];
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    _sol();
}
