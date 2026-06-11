#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k,ans;
  ans = 0;
  cin >> n  >> k;
  vector<int> a(n);
  for(int i=0;i<k;i++){
    int d;
    cin >> d;
    vector<int> vec(d);
    for(int j=0;j<d;j++){
      int p;
      cin >> p;
      a.at(p-1) = 1;
    }
  }
  for(int i=0;i<n;i++){
    if(a.at(i) == 0)
      ans++;
  }
  cout << ans;
}
    