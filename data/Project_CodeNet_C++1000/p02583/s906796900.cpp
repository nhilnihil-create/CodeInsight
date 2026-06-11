#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin>>n;
  int l[n];
  for (int i=0;i<n;i++){
    int e; cin>>e;
    l[i]=e;
  }
  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(l[i]==l[j]){continue;}
      for(int k=j+1;k<n;k++){
        if(l[j]==l[k] || l[i]==l[k]){continue;}
        if(l[i]+l[j]>l[k] & l[i]+l[k]>l[j] & l[k]+l[j]>l[i]){
          ans+=1;
        }
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}