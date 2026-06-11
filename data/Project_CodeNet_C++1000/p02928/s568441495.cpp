

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
#define oset tree<long long, null_type,less_equal<long long>, rb_tree_tag,tree_order_statistics_node_update>
using ll = long long;
ll mod=1e9+7;




int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        ll n,k,i;
        cin>>n>>k;
        oset s,s2;
        ll a[n+2];
        for(i=0;i<n;i++){
            cin>>a[i];
            s2.insert(a[i]);
        }
        
        ll bigonR[n+2],bigger[n+2];
        for(i=0;i<n;i++){
            bigger[i] = s2.order_of_key(a[i]);
        }
        
        
        for(i=n-1;i>=0;i--){
            bigonR[i]=s.order_of_key(a[i]);
            s.insert(a[i]);
            
        }
        ll sum=0;
        for(i=0;i<n;i++){
            // cout << bigger[i] << ' ' << bigonR[i] << "\n";
            ll kk = (k * (k - 1)) / 2;
            kk %= mod;
            sum += ((bigger[i] * kk) % mod);
            sum %= mod;
            sum += ((bigonR[i] * k) % mod);
            sum %= mod;
        }
        cout << sum;
        cout<<"\n";
    }
}


