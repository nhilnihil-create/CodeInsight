#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  if(n>1 & m==0){
    cout<<pow(10,n-1)<<endl;
    exit(0);
  }
  else if(n==1 & m==0){
    cout<<0<<endl;
    exit(0);
  }
  vector<vector<int>> v(m,vector<int>(2));
  for(int i=0;i<=m-1;i++){
    int s,c;
    cin>>s>>c;
    if(s==1 & c==0 & n>=2){
      cout<<-1<<endl;
      exit(0);
    }
    else if(s==1 & c==0 & n==1){
      cout<<0<<endl;
      exit(0);
    }
    v[i][0]=s;
    v[i][1]=c;
  }
  sort(v.begin(),v.end());
  vector<int> ans(m,0);
  bool flag=true;
  for(int i=0;i<=m-2;i++){
    if(v[i][0]==v[i+1][0]){
      if(v[i][1]==v[i+1][1]){
        continue;
      }
      else{
        flag=false;
        cout<<-1<<endl;
      }
    }
  }
  if(flag){
    for(int i=0;i<=m-1;i++){
      ans[v[i][0]-1]=v[i][1];
    }
  }
  if(flag){
    for(int i=0;i<=n-1;i++){
      if(i==0 &ans[0]==0){
        cout<<1;
      }
      else{
        cout<<ans[i];
      }
    }
  }
  return 0;
}