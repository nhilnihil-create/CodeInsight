#include<iostream>
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <iomanip>//setprecision
#include<math.h>
#include <functional>
#include<climits>
using namespace std;
template <typename T> bool chmax(T &u, const T z) { if (u < z) {u = z; return true;} else return false; }
template <typename T> bool chmin(T &u, const T z) { if (u > z) {u = z; return true;} else return false; }
const int INF=10000000;
#define ll  long long 
#define rep(i, n)        for(ll i=0; i<(ll)(n); ++i)
int main(){
  int h,w,n;cin>>h>>w>>n;
  map<int,int>mph,mpw;
  set<pair<int,int>>zahyou;
  rep(i,n){
    ll r,c;
    cin>>r>>c;
    zahyou.insert({r,c});
    mph[r]++;
    mpw[c]++;
  }
  int maxh=0,maxw=0;
  for(auto p:mph)chmax(maxh,p.second);
  for(auto p:mpw)chmax(maxw,p.second);
  vector<int>numh,numw;
  for(auto p:mph)if(p.second==maxh)numh.push_back(p.first);
  for(auto p:mpw)if(p.second==maxw)numw.push_back(p.first);
  rep(i,numh.size())rep(o,numw.size()){
    if(!zahyou.count({numh[i],numw[o]})){
      cout<<maxh+maxw<<endl;
      return 0;
    }
  }
  cout<<maxh+maxw-1<<endl;
}