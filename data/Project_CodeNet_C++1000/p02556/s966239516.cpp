#include<bits/stdc++.h>
using namespace std;
int main(){
int n; cin>>n;
int x,y;
typedef pair<int,int> pii;
#define fi first
#define se second
multiset<pii> ms;
for(int i=0;i<n;i++) { cin>>x>>y; ms.emplace(x,y); }
set<int> s1,s2;
int ans=0; 
for(auto& i:ms){
if(!s1.empty()){ int cv1=i.fi+i.se,cv2=i.fi-i.se; ans=max(ans,max(cv1-*s1.begin(),cv2-*s2.begin()));  }
s1.emplace(i.fi+i.se); s2.emplace(i.fi-i.se);
}
cout<<ans<<'\n'; 
return 0;
}