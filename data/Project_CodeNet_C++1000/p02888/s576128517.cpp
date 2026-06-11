#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;  cin >> n;
  vector<int> l(n+1);  l[n] = 1e9;
  for(int i=0; i<n; i++)  cin >> l[i];
  sort(l.begin(), l.end());

  int ans = 0;
  for(int i=0; i<n-2; i++)    
    for(int j=i+1; j<n-1; j++)
      ans += (int)(lower_bound(l.begin()+j, l.end(), l[i]+l[j]) - l.begin()) - j - 1;

  cout << ans << endl;

  return 0;
}
