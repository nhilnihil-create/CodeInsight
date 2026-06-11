#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

char grid[2020][2020];
vector<int> bh[2020],bw[2020];

bool isOK(int index, int i, vector<int> &vec){
  if(vec[index]<i) return 1;
  else return 0;
}

int nibutan(int i, vector<int> &vec){
  int left = 0, right = vec.size()-1;
  while(right-left>1){
    int middle=(left+right)/2;
    if(isOK(middle,i,vec)) left = middle;
    else right = middle; 
  }
  return vec[right]-vec[left]-1;
}

int main(){
  int h,w;
  cin>>h>>w;
  rep(i,h)rep(j,w) cin>>grid[i][j];
  rep(i,h){
    bh[i].push_back(-1);
    rep(j,w){
      if(grid[i][j]=='#') bh[i].push_back(j);
    }
    bh[i].push_back(w);
  }
  rep(j,w){
    bw[j].push_back(-1);
    rep(i,h){
      if(grid[i][j]=='#') bw[j].push_back(i);
    }
    bw[j].push_back(h);
  }

  int ans=0;
  rep(hi,h)rep(wi,w){
    if(grid[hi][wi]=='#') continue;
    int H = nibutan(wi,bh[hi]), W = nibutan(hi,bw[wi]);
    ans=max(ans,H+W-1);
  }
  cout<<ans<<endl;
}
