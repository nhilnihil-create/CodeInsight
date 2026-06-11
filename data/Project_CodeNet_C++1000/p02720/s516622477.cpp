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
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
using Graph=vector<vector<int>>;
using edge= struct{int to;ll cost;};
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}
typedef priority_queue<ll> PQ_HIGH;
typedef priority_queue<ll,VL,greater<ll>> PQ_LOW;//昇順

void test(priority_queue<pair<ll,ll>> que){
  while(!que.empty()){
    cout<<que.top().first<<" "<<que.top().second<<endl;
    que.pop();
  }
}

int main(){
  ll k;cin>>k;
  queue<ll> a;
  for(int i=1;i<10;i++){
    a.push(i);
  }
  ll top=1;
  for(int i=0;i<k;i++){
    top=a.front();
    a.pop();
    if(top%10==0){
      ll tmp1=top*10;
      ll tmp2=top*10+1;
      a.push(tmp1);
      a.push(tmp2);
    }
    else if(top%10==9){
      ll tmp1=top*10+8;
      ll tmp2=top*10+9;
      a.push(tmp1);
      a.push(tmp2);
    }
    else{
      ll tmp1=top*10+top%10-1;
      ll tmp2=top*10+top%10;
      ll tmp3=top*10+top%10+1;
      a.push(tmp1);
      a.push(tmp2);
      a.push(tmp3);
    }
  }
  cout<<top<<endl;
}