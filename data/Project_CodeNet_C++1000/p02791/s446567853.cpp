#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,mi,ans;
  cin >> n;
  vector<int> p(n);
  for(int i=0;i<n;i++){
    cin >> p.at(i);
  }
  mi = p.at(0);
  for(int i=0;i<n;i++){
    if(p.at(i) <= mi){
      ans++;
    }
    mi = min(mi,p.at(i));
  }
  cout << ans << endl;
}