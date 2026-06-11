#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll=long long;

ll n,k;

ll search(vector<ll> a,vector<ll> f){
     ll l=-1,r=1e17+1;
     while(abs(l-r)>1){
         ll mid=(l+r)/2;
         ll cnt=0;
         for(int i=0;i<n;i++){
             cnt+=max(0ll,a[i]-mid/f[i]);
         }
         if(cnt>k)l=mid;
         else r=mid;
     }
     return r;
}

int main(){
    cin>>n>>k;
    vector<ll> a(n),f(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>f[i];
    sort(a.begin(),a.end());
    sort(f.begin(),f.end(),greater<>());
    cout<<search(a,f)<<endl;
}
