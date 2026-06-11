#include<bits/stdc++.h>
using namespace std;
const int minn=1001001001;
int a[12][12];

int main(){
int n,m,x;
cin>>n>>m>>x;
vector<int> c(n);
for(int i=0;i<n;i++){
  cin>>c[i];
  for(int j=0;j<m;j++){
    cin>>a[i][j];
  }
}
int ans=minn;
for(int s=0;s<(1<<n);s++){
  int cost =0;
  vector<int> d(m);
  for(int i=0;i<n;i++){
    if(s&(1<<i)){
      cost+=c[i];
      for(int j=0;j<m;j++){
        d[j]+=a[i][j];
      }
    }
  }
  bool ok=true;
  for(int j=0;j<m;j++){
    if(d[j]<x){
      ok=false;
    }
  }
  if(ok){
      ans=min(ans,cost);
    }
  
}
if(ans==minn){
  cout<<-1<<endl;
}
else{
  cout<<ans<<endl;
}
return 0;
}
