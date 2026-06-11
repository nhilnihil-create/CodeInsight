#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll res = 0;
    rep(i,n){
        res = res^a[i];
    }
    if(res==0) cout << "Yes" << endl;
    else cout << "No" << endl;
}