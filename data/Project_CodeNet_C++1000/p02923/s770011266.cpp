#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<int> k(n);
  for(int i=0; i<n; i++) cin >> k[i];
  
  int count = 0;
  int ans = 0;
  
  if(n == 1) cout << 0 << endl;
  
  else{
  for(int i=0; i<=max(n-2,0); i++){
    if(k[i] >= k[i+1]) count++;
    else{
      if(count >= ans) ans = count;
      count = 0;
    }
  }
  
  if(count != 0) ans = max(count,ans);
  
  cout << ans << endl;
  }
	return 0;
}
