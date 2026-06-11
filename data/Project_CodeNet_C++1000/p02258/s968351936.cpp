#include<bits/stdc++.h>
#define int long long

#define MAX_N 200000

using namespace std;

signed main(){
  int n, r[MAX_N];
  
  cin >> n;
  for(int i=0;i<n;i++) cin >> r[i];

  int minv = r[0];
  int maxv = r[1] - r[0];
  for (int i=1;i<n;i++) {
    maxv = max(maxv, r[i] - minv);
    minv = min(minv, r[i]);
  }

  cout << maxv << endl;
}