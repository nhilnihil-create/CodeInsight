#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define REP(i,n) for (ll i=1;i<=(n);i++)
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    vector<ll> num(n+1,0);
    REP(i,n){
        cin >> a[i];
        num[a[i]]++;
    }
    ll def=0;
    REP(i,n){
        if(num[i]>=2){
            ll s = num[i]*(num[i]-1)/2;
            def += s;
        }
    }
    
    REP(i,n){
        if(num[a[i]]<=1){
            cout << def << endl;
        }else{
            cout << def-num[a[i]]+1 << endl;
        }
    }
}