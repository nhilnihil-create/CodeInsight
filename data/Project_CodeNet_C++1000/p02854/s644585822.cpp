#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;


int main(){
ll n; cin>>n;
ll iron[200000];
ll rui1[200000];
ll rui2[200000];
ll zen = 0;
for(int i = 0;i<n;i++)cin>>iron[i], zen+=iron[i];
rui1[0]=0;
rui2[0]=zen;
for(int i=0;i<n;i++){
rui1[i+1]=rui1[i]+iron[i];
rui2[i+1]=rui2[i]-iron[i];
}
ll ans = 202020202020;
for(int i=0;i<n;i++){
ll kari=abs(rui1[i]-rui2[i]);
ans=min(kari,ans);
}
cout<<ans<<endl;
}
