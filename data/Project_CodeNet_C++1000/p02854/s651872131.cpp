#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll l = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        l += a[i];
    }
    pair<ll,ll> mn = {mod*mod,-1};
    vector<ll> L(n);
    ll mid,now = 0;
    for(ll i = 0; i < n; i++){
        now += a[i];
        L[i] = now;
        if(2*L[i] >= l){
            if(i == 0){
                cout << a[0]-(l-a[0]) << endl;
                return 0;
            }
            if(abs(l-2*L[i]) > abs(l-2*L[i-1])){
                cout << abs(L[i-1]-(l-L[i-1])) << endl;
                return 0;
            }
            else{
                cout << abs(L[i]-(l-L[i])) << endl;
                return 0;
            }
        }
    }
    return 0;
}