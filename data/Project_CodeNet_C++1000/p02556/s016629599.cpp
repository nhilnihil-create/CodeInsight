#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int x,y;
  int z[200100];
  int w[200100];
  for(int i=0;i<N;i++){
    cin>>x>>y;
    z[i]=x+y;
    w[i]=x-y;
  }
  int maxz=z[0];
  int minz=z[0];
  int maxw=w[0];
  int minw=w[0];

  for(int i=1;i<N;i++){ 
    maxz=max(maxz,z[i]);
    minz=min(minz,z[i]);
    maxw=max(maxw,w[i]);
    minw=min(minw,w[i]);    
  }
  int ans=0;
  ans=max(maxz-minz,maxw-minw);
  cout<<ans<<endl;
  return 0;
}

  