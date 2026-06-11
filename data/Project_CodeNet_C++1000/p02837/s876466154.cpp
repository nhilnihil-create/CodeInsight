#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <cmath>
#include <algorithm>
#include <vector>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
vector<pair<int64_t,int64_t>>func(int64_t x){
  vector<pair<int64_t,int64_t>>p;
  for(int64_t i=2;i*i<=x;i++){
    int cnt=0;
    if(x%i==0){
    while(x%i==0){cnt++;x/=i;}
    p.push_back(make_pair(i,cnt));
    }
  }
  if(x!=1){p.push_back(make_pair(x,1));}
  return p;
}

int main(){
  int N;
  cin>>N;
  int g[20][20];
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      g[i][j]=-1;
    }
  }
  for(int i=0;i<N;i++){
    int A;
    cin>>A;
    for(int j=0;j<A;j++){
      int x,y;
      cin>>x>>y;
      x--;
      g[i][x]=y;
    }
  }
  int ans=0;
  for(int s=0;s<(1<<N);s++){
    vector<int>d(N);
    for(int i=0;i<N;i++){
      if((s>>i)&1){d[i]=1;}
    }
    bool ok=true;
    for(int i=0;i<N;i++){
      if(d[i]){
      for(int j=0;j<N;j++){
        if(g[i][j]==-1){continue;}
        if(g[i][j]!=d[j]){ok=false;}
      }
    }
  }
    if(ok){ans=max(ans,__builtin_popcount(s));}
  }
  cout<<ans<<endl;
  return 0;
}