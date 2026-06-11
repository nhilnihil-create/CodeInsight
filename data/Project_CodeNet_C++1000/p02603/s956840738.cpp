#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll MOD=1000000007;
ll n;
ll a[100];
ll ans=1000;
ll k;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        if(a[i-1]<a[i]){
            k=ans/a[i-1];
            ans=ans-k*a[i-1];
            ans=ans+k*a[i];
        }
    }
    cout<<ans<<endl;
    
}
