#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k,c,p,sum=0;
  bool tf=false;
  cin>>n>>k>>c;
  char a[n];
  bool b[n],d[n];
  for(int i=0;i<n;i++){
    char t;
    cin>>t;
    a[i]=t;
    if(t=='o')sum++;
    b[i]=false;
    d[i]=false;
  }
  p=k;
  for(int i=0;i<n;i++){
    if(a[i]=='o'){
      b[i]=true;
      i+=c;
      p--;
    }
  }
  if(sum==k){
    for(int i=0;i<n;i++){
      if(b[i])cout<<i+1<<endl;
    }
  }
  else if(p<0){
  }
  else{
    for(int i=n-1;i>=0;i--){
      if(a[i]=='o'){
        d[i]=true;
        i-=c;
      }
    }
    for(int i=0;i<n;i++){
      if(b[i]==true&&d[i]==true)cout<<i+1<<endl;
    }
  }
}