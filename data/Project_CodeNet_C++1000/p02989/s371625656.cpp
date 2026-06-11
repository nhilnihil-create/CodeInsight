#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int>a(n);
  for(int i=0;i<n;++i){
    cin >> a[i];
  }
  int ans=0;
  sort(a.begin(),a.end());
  ans=a.at(n/2)-a.at(n/2-1);
  cout << ans << endl;
  return 0;
}