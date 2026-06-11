#define _LIBCPP_DEBUG 0
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD = 1e9 + 7;


int main(void) {

    ll n; cin>>n;
    cout<<n<<":";
    map<ll,ll> mp;
    ll i;
    for (i = 2; i*i <= n; ++i) {
        if(n%i==0){
            while (n%i==0){
                n /= i;
                mp[i]++;
            }
        }
        if(n==1) break;
    }
    if(n!=1) mp[n]++;

    for(auto it : mp){
        for (int i = 0; i < it.second; ++i) {
            cout<<" "<<it.first;
        }
    }
    cout<<endl;
    
    return 0;
}
