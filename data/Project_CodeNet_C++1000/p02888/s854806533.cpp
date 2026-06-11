#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> l(n);
  for (int i = 0;i < n;i++){
    cin >> l[i];
  }
  int ans = 0;
  sort(l.begin(), l.end());
  
  for (int i = 0;i < n-2;i++){
    int k = i+2;
    for (int j = i+1;j < n-1;j++){
      while (l[i] + l[j] > l[k] && k < n){
        k++;
      }
      ans += (k-j-1);
    }
  }
  
  cout << ans << endl;
}