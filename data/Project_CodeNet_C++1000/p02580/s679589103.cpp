#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <map>

#define rep0(i, n) for (i = 0; i < n; i++)
#define rep(s, i, n) for (i = s; i < n; i++)
using namespace std;

#define INF 1<<30

int main(){
  int h,w,m,i,wi,hi;
  cin>>h>>w>>m;
  vector<map<int,int> > target(h);
  vector<int> row(h);
  vector<int> col(w);
  rep0(i,m){
    int hi,wi;
    cin>>hi>>wi;
    hi--;wi--;
    target[hi][wi] = 1;
    row[hi]++;
    col[wi]++;
  }
 
  int c_max = 0;
  rep0(wi,w)c_max=max(c_max,col[wi]);
  vector<int> w_candidate;
  rep0(wi,w)
    if(col[wi]==c_max)
      w_candidate.push_back(wi);
  
  int ans = 0;
  rep0(hi,h)for(int wi:w_candidate){
    if(target[hi].count(wi))
      ans = max(ans,row[hi]+col[wi]-1);
    else{
      ans = max(ans,row[hi]+col[wi]);
      break;
    }
  }
 
  cout<<(ans)<<endl;
  return 0;
}