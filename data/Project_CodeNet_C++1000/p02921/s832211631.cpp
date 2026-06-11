#include<bits/stdc++.h>
using namespace std;
int main(){
  string a,b;cin>>a>>b;
  int ans=0;
  if(a[0]==b[0])ans+=1;
  if(a[1]==b[1])ans+=1;
  if(a[2]==b[2])ans+=1;
  cout<<ans<<endl;
}