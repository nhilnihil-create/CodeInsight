#include<bits/stdc++.h>
using namespace std;
int main(){
int n;cin>>n;
vector<int> d(n);
for(int& i:d) cin>>i;
int ans=0,s=d[n-1];
for(int i=n-2;i>=0;i--){ans+=(d[i]*s); s+=d[i]; }
cout<<ans<<endl;
return 0;
} 