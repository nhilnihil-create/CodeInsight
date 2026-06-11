#include <iostream>
#include <vector>
#include <bitset>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
 
using namespace std;
typedef long long ll;
 
int main(){
  int N,D,A;
  cin >> N >> D >> A;
  vector<pair<int,int>> v(N+1);
  v[N]=make_pair(1000000010,0);
  for(int i=0;i<N;i++){
    cin >> v[i].first >> v[i].second;
    v[i].second=(v[i].second+A-1)/A;
  }
  
  sort(v.begin(), v.end());

  vector<int> d(N+1,0);

  int cur=0;
  ll ans=0;
  for(int i=0;i<N;i++){
    cur-=d[i];
    //cout << v[i].first << " " << cur;
    if(cur<v[i].second){
      ans+=v[i].second-cur;
      int n=distance(v.begin(),upper_bound(v.begin(),v.end(),make_pair(v[i].first+2*D+1,0)));
      d[n]+=v[i].second-cur;
      cur+=v[i].second-cur;
    }
    //cout << " " << ans << endl;
  }

  cout << ans << endl;
  
  return 0;
}
