#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
int n; cin>>n;
ll a[n]; for(int i=0;i<n;i++) cin>>a[i];
sort(a,a+n); 
ll ans=a[n-1];
int i=0,k=n-2;
for(int i=0;i<n-2;i++){
if(i%2==0){ ans+=a[k]; }
else { ans+=a[k]; k--; }
}
cout<<ans<<endl;
}
 