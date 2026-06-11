#include <bits/stdc++.h>
using namespace std;

long long a[500005];

void A(){
  a[0]=0;
  for(int i=1;i<500005;i++){
    a[i]=a[i-1]+i;
  }
}

int main(){
  A();
  string s;
  cin>>s;
  int n=s.size();
  long long ans=0;
  vector<int> R,L;
  int cnt=1;
  
  char mem=s[0];
  for(int i=1;i<n;i++){
    if(mem==s[i]) cnt++;
    else{
      if(mem=='<') R.push_back(cnt);
      else L.push_back(cnt);
      cnt=1;
    }
    mem=s[i];
  }
  if(mem=='<') R.push_back(cnt);
  else L.push_back(cnt);
  
  int r=R.size(),l=L.size();
 if(s[0]=='<'){
  if(r==l){
    for(int i=0;i<r;i++){
      ans+=a[R[i]]+a[L[i]]-min(R[i],L[i]);
    }
  }
  else{
    for(int i=0;i<l;i++){
      ans+=a[R[i]]+a[L[i]]-min(R[i],L[i]);
    }
    ans+=a[R[l]];
  }
 }
 else{
   if(r!=l){
     ans+=a[L[0]];
   	 for(int i=0;i<r;i++){
     ans+=a[R[i]]+a[L[i+1]]-min(R[i],L[i+1]);
     }
   }
   else{
     ans+=a[L[0]];
   	 for(int i=0;i<r-1;i++){
     ans+=a[R[i]]+a[L[i+1]]-min(R[i],L[i+1]);
     }
     ans+=a[R[r-1]];
   }
 } 
  cout<<ans<<endl;
}