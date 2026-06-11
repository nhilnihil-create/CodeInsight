#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,d;
  cin >> n >> d;
  vector<vector<int>> list(n,vector<int>(d));
  for(int i=0; i<n; i++) {
    for(int j=0; j<d; j++) {
      cin >> list.at(i).at(j);
    }
  }
  int ans = 0;
  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) {
      int jud = 0;
      for(int k=0; k<d; k++) {
        int p = abs(list[i][k]-list[j][k]);
        jud += p*p;
      }
      bool f=false;
      for(int k=0; k<=jud; k++) {
        if(jud == k*k) {
          f = true;
        }
      }
      if(f) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}