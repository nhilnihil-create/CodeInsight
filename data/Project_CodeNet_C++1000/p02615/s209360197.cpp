#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t n;
  cin >> n;
  vector<int64_t>al(n);
  for(int64_t i=0;i<n;i++)
    cin >> al.at(i);
  sort(al.begin(),al.end(),greater());
  int64_t ans=0;
  for(int64_t i=1;i<n;i++){
    ans+=al.at(i/2);
  }
  cout << ans << endl;
  return 0;
}
  