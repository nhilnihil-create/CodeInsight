#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
const ll MOD=1e9+7;

#define int long long
signed main(){
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int n;
    cin >> n;
    ll a[n];
    ll mx=0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mx=max(mx,a[i]);
    }
    int m=60;
    //int m=log2(mx)+1;
    int bcnt[m]={};
    for(int i = 0; i < n; i++) {
        ll bit=a[i];
//        cout << bitset<60>(bit) << "\n";
        for(int j = 0; j < m; j++) {
            if(bit & ((ll)1<<j)) bcnt[j]++;
        }
    }
//    for(int i = 0; i < 60-m; i++) {
//        cout << "0";
//    }
//    for(int i = 0; i < m; i++) {
//        cout << bcnt[m-i-1];
//    }
//    cout << "\n";

    ll ans=0;
    ll bn =1;
    for(int i = 0; i < m; i++) {
        ll tmp=((n-bcnt[i])*bcnt[i])%MOD;
        ans=(ans+tmp*bn)%MOD;
        bn=(bn*2)%MOD;
    }
    cout << ans << "\n";
    return 0;
}