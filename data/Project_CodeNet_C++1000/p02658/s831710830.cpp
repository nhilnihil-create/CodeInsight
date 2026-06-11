#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
        if(a[i]==0){
            cout << 0 << endl;
            return 0;
        }
    }
    ll now = 1;
    ll lim = 1e18;
    rep(i,n){
        if(a[i] > lim/now){
            cout << -1 << endl;
            return 0;
        }
        else{
            now*=a[i];
        }
    }
    cout << now << endl;
    return 0;
}