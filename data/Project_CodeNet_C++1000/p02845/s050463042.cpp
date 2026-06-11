#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n,c[3]={0,0,0};
    cin >> n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    ll sum=1;
    for(ll i=0;i<n;i++){
        ll cnt=0,id=-1;
        if(a[i]==c[0]){
            cnt++;
            id=0;
        }
        if(a[i]==c[1]){
            cnt++;
            id=1;
        }
        if(a[i]==c[2]){
            cnt++;
            id=2;
        }
        if(id==-1){
            cout << 0 << endl;
            return 0;
        }
        sum*=cnt;
        c[id]++;
        sum%=MOD;
    }
    cout << sum << endl;
}