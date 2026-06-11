#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,m,sum=0, a;
  string ans;
  cin >> n >> m;
  vector<int> v(n);
  for(int i=0; i<n; i++){
    cin >> v.at(i);
    sum += v.at(i);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(),v.end());
  if(v.at(m-1) >= sum/(4*double(m))){
    ans = "Yes";
  }else{
    ans = "No";
  }
  cout << ans << endl;
}