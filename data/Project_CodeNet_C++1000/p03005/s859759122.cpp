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
  int n,k;cin>>n>>k;
  vector<int> ans(k,0);
  for(int i=0;i<n;i++){
    if(i<k){
      ans[i]++;
    }else{
      ans[0]++;
    }
  }
  cout<<ans[0]-ans[k-1]<<endl;
}