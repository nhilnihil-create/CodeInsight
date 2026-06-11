#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  long long n, k;
  cin >> n >> k;
  if(k > (n-1)*(n-2)/2ll){
    cout << -1 << endl;
    return 0;
  }
  vector<pair<int, int> > ans;
  for(int i=1;i<n;i++){ //uni
    ans.push_back(make_pair(0, i));
  }
  k-=(n-1)*(n-2)/2ll;
  int now=1;
  while(k != 0){
    for(int i=now+1;i<n;i++){
      if(k==0) break;
      ans.push_back(make_pair(now, i));
      k++;
    }
    now++;
  }
  cout << ans.size() << endl;
  for(size_t i=0;i<ans.size();i++){
    cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
  }
  return 0;
}
