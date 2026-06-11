#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  for (int i=0 ; i<n ; i++)
    cin >> h.at(i);
  
  int ans = 0;
  for (int i=0 ; i<n ; i++){
    if (h.at(i) >= k)
      ans++;
  }
  
  cout << ans << endl;
}