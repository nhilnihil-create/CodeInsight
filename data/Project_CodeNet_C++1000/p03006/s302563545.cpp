#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <functional>
#include <stack>
#include <iomanip>
#include <limits>
using namespace std;
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<double> VD;

#define INF 1e+9
#define MAX_V 300

struct edge {
    int to;
    int cost;
};
using P = pair<ll, ll>;
int main(){
  int n;cin>>n;
  vector<pair<ll,ll>> ball(n);
  for(int i=0;i<n;i++){
    ll x,y;cin>>x>>y;
    ball[i]=make_pair(x,y);
  }
  sort(ball.begin(),ball.end());
  /*
  for(int i=0;i<n;i++){
    cout<<ball[i].first<<" "<<ball[i].second<<endl;
  }
  */
  ll min=50;
  if(n==1){cout<<1<<endl;return 0;}
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      ll d_x=ball[j].first-ball[i].first;
      ll d_y=ball[j].second-ball[i].second;
      vector<bool> seen(n,false);
      int ow=0;
      seen[ow]=true;
      int count=1;
      int seen_num=1;
      int xt=1;
      while(true){
        if(ball[xt].first-ball[ow].first==d_x&&ball[xt].second-ball[ow].second==d_y&&seen[xt]==false){
          seen[xt]=true;
          ow=xt;
          seen_num++;
          xt++;
        }else{
          xt++;
        }
        if(xt>=n){
          for(int i=0;i<n;i++){
            if(seen[i]==false){
              ow=i;
              seen[ow]=true;
              seen_num++;
              xt=ow+1;
              count++;
              break;
            }
          }
        }
        if(seen_num==n){
          break;
        }
      }
      if(count<min){
        min=count;
      }
    }
  }
  cout<<min<<endl;
}