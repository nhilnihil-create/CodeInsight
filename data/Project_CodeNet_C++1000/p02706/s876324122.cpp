#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m, sum = 0;
  cin >> n >> m;
  vector<int> a(m);
  for (int i=0 ; i<m ; i++){
    cin >> a.at(i);
    sum += a.at(i);
  }
  
  if (sum <= n)
    cout << n - sum << endl;
  else
    cout << -1 << endl;
}