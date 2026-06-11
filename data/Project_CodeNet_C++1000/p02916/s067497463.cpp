#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  vector<int> c(n-1);
  for (int i=0 ; i<n ; i++)
    cin >> a.at(i);
  for (int i=0 ; i<n ; i++)
    cin >> b.at(i);
  for (int i=0 ; i<n-1 ; i++)
    cin >> c.at(i);
  
  int ans = 0;
  for (int i=0 ; i<n ; i++)
    ans += b.at(a.at(i)-1);
  for (int i=0 ; i<n-1 ; i++){
    if (a.at(i+1) == a.at(i) + 1)
      ans += c.at(a.at(i)-1);
  }
  
  cout << ans << endl;
}