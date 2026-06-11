#include<bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  int smallest_so_far = n+1;
  int ans=0;
  for(int i=0;i<n;i++) {
    if(smallest_so_far > a[i]) {
      ans++;
      smallest_so_far = a[i];
    }
  }
  cout << ans << "\n";
}