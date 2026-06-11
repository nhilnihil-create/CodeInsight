#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> an(n);
  for(int i=0; i<n; ++i) cin >> an[i];
  int ans = 0, cnt = 0;
  for(int i=0; i<n-1; ++i){
    if(an[i] >= an[i+1]) ++cnt;
    else cnt = 0;
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}