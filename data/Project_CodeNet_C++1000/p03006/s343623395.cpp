#include <bits/stdc++.h>
using namespace std;

const int N_MAX=50;
int N;
vector<int64_t> x(N_MAX),y(N_MAX);

int main(){
  cin>>N;
  map<pair<int64_t,int64_t>,int> S;
  for(int i=0;i<N;++i){
    cin>>x[i]>>y[i];
    ++S[make_pair(x[i],y[i])];
  }

  int ans=100;
  if(N==1) ans=1;
  else{
  for(int i=0;i<N;++i){
    for(int j=0;j<N;++j){
      if(i==j) continue;
      int cnt=0;
      int64_t a=x[i]-x[j],b=y[i]-y[j];
      for(int k=0;k<N;++k){
        if(S[make_pair(x[k]-a,y[k]-b)]==0) ++cnt;
      }
      ans=min(cnt,ans);
    }
  }
  }
  cout<<ans<<endl;
}