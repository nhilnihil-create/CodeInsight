#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
const int INF = 2001001001;

int main(){
  int n, x, l;
  cin >> n;
  vector<P> arm(n);
  for(int i=0; i<n; ++i){
    cin >> x >> l;
    arm[i].first = x+l;
    arm[i].second = x-l;
  }
  sort(arm.begin(),arm.end());
  
  int ans=0, mx = -INF;
  for(int i=0; i<n; ++i){
    if(arm[i].second >= mx){
      ++ans;
      mx = arm[i].first;
    }
  }
  cout << ans << endl;
}