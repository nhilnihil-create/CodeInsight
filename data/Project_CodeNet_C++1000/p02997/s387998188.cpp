#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

int main(){
  int n, k;
  cin >> n >> k;
  if((n-1) *(n-2) /2 < k){
    cout << -1 << endl;
    return 0;
  }
  int mx = (n-1) *(n-2) /2;
  vector<P> ans(0);
  for(int i=2; i<=n; ++i){
    ans.push_back(P(1,i));
  }
  for(int i=2; i<n; ++i) for(int j=i+1; j<=n; ++j){
    if(mx > k){
      ans.push_back(P(i,j));
      --mx;
    }else break;
  }
  
  cout << ans.size() << endl;
  for(auto pi: ans){
    printf("%d %d\n",pi.first,pi.second);
  }
}