#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
template<class T> void chmin(T &a,const T &b){if(a>b) a=b;}
template<class T> void chmax(T &a,const T &b){if(a<b) a=b;}

int mostBit(int val){
    for(int i=20;i>=0;i--){
        if((1<<i)&val) return i;
    }
    return -1;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin>>N;

  for(int i=0;i<20;i++){
      if((1<<i)==N){
          cout<<"No"<<endl;
          return 0;
      }
  }

  vector<pair<int,int>> ans;
  for(int i=3;i<=N;i+=2){
      ans.push_back(mkp(i-1,1));
      ans.push_back(mkp(i-1,i));
      ans.push_back(mkp(N+i,1));
      ans.push_back(mkp(N+i,N+i-1));
  }
  ans.push_back(mkp(N+1,3));

  if(N%2==0){
      int a=(1<<mostBit(N))+1;
      int b=N+1-a;
      ans.push_back(mkp(N,b));
      ans.push_back(mkp(N+N,N+a));
  }

  cout<<"Yes"<<endl;
  for(auto v:ans) cout<<v.first<<" "<<v.second<<endl;

  return 0;
}
