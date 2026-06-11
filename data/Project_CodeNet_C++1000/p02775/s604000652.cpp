#include<bits/stdc++.h>
using namespace std;
int main(){
  string n;
  int l,m,f,i,ans=0;
  cin>>n;
  l=n.length();
  f=0;
  for(i=l-1;i>=0;i--){
    m=n.at(i)-'0'+f;
    if(m<=4){
      ans+=m;
      f=0;
    }
    else if(6<=m){
      ans+=10-m;
      f=1;
    }
    else if(m==5){
      if(i>0 && n.at(i-1)-'0'>=5){
        ans+=10-m;
        f=1;
      }
      else{
        ans+=m;
        f=0;
      }
    }
  }
  ans+=f;
  cout<<ans<<endl;
}