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

ll mod=1000000007;

int main(){
  int n;cin>>n;
  ll r,g,b;
  r=g=b=0;
  ll ans=1;
  for(int i=0;i<n;i++){
    int count=0;
    ll tmp;cin>>tmp;
    if(tmp==r){count++;}
    if(tmp==g){count++;}
    if(tmp==b){count++;}
    ans*=count;
    ans%=mod;
    if(tmp==r){r++;continue;}
    if(tmp==g){g++;continue;}
    if(tmp==b){b++;continue;}
  }
  cout<<ans<<endl;
}