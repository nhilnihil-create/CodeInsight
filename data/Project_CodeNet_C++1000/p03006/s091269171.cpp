#include<bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
int main(){
  int N,i,j,k,x,y;scanf("%d",&N);
  pair<int,int> B[N];map<pair<int,int>,int> mp;
  for(i=0;i<N;i++){
    scanf("%d%d",&x,&y);
    B[i] = make_pair(x,y);
    mp[make_pair(x,y)] = i;
  }
  int ans = N,now,nx,ny;queue<pair<int,int>> q;
  for(i=0;i<N-1;i++){
    for(j=i+1;j<N;j++){
      x = B[i].first-B[j].first;y = B[i].second-B[j].second;
      bool use[N] = {};now = 0;
      for(k=0;k<N;k++){
        if(use[k]) continue;
        use[k] = true;
        nx = B[k].first+x;ny = B[k].second+y;
        while(mp.count(make_pair(nx,ny))){
          use[mp[make_pair(nx,ny)]] = true;
          nx += x;ny += y;
        }
        nx = B[k].first-x;ny = B[k].second-y;
        while(mp.count(make_pair(nx,ny))){
          use[mp[make_pair(nx,ny)]] = true;
          nx -= x;ny -= y;
        }
        now++;
      }    
      ans = min(ans,now);
    }
  }
  printf("%d\n",ans);
}