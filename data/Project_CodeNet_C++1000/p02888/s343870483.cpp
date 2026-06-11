#include<bits/stdc++.h>
using namespace std;
int main(){
int n; cin>>n;
vector<int> l(n);
for(int& i:l) cin>>i;
sort(l.begin(),l.end()); 
int ans=0;
for(int i=0;i<n;i++){
for(int j=i+1;j<n;j++){ 
int s1=l[i]+l[j],s2=max(l[i]-l[j],l[j]-l[i]); 
auto itr1=lower_bound(l.begin()+(j+1),l.end(),s1);
auto itr2=upper_bound(l.begin()+(j+1),itr1,s2); 
ans+=(itr1-itr2); 
}
}
cout<<ans<<endl;
return 0;
}
