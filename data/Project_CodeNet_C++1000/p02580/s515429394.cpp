#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=1e9+7;

int main(){
  int H,W,M;
  cin>>H>>W>>M;
  vector<int64_t>h(H),w(W);
  set<pair<int,int>>q;
  for(int i=0;i<M;i++){
    int y,x;
    cin>>y>>x;
    y--;x--;
    h[y]++;w[x]++;
    q.insert(make_pair(y,x));
  }
  int64_t MXh=*max_element(h.begin(),h.end());
  int64_t MXw=*max_element(w.begin(),w.end());
  vector<int>hmx,wmx;
  for(int i=0;i<H;i++){
    if(h[i]==MXh){hmx.push_back(i);}
  }
  for(int j=0;j<W;j++){
    if(w[j]==MXw){wmx.push_back(j);}
  }
  for(int i:hmx){
    for(int j:wmx){
      if(!q.count(make_pair(i,j))){
        cout<<MXh+MXw<<endl;return 0;//全部使っていたとするときのループが最悪のケースだが、それはMケースのみ
      }
    }
  }
  cout<<MXh+MXw-1<<endl;
  return 0;
}