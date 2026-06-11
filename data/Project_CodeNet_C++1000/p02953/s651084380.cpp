#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
  cin >> n;
  long long h[n];
  string ans = "Yes";
  for(int i = 0; i < n; i++) cin >> h[i];
  for(int i = n-2; i > 0; i--){
    if(h[i]>h[i+1]) h[i]--;
     if(h[i]>h[i+1]){
      ans = "No";
    }
  }
  cout << ans << endl;
}
