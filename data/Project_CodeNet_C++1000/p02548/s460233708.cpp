#include<bits/stdc++.h>
#define PI 3.141592653589793238462
using namespace std;
typedef long long ll;
typedef long double db;
int a[105],b[105];
int main(){
    ll n,ans=0;cin>>n;
    for(ll i=1;i<=n;i++){
        ans+=(n-1)/i;
    }
    cout<<ans<<endl;
}