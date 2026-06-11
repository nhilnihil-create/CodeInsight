#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> w(n);
  for (int i = 0;i < n;i++){
    cin >> w[i];
  }
  
  int ans = 1000000000;
  for (int t = 1;t < n;t++){
    int s1 = 0,s2 = 0;
    for (int i = 0;i < n;i++){
      if (i < t){
        s1 += w[i];
      }
      else{
        s2 += w[i];
      }
    }
    ans = min(ans,abs(s1-s2));
  }

  cout << ans << endl;
}