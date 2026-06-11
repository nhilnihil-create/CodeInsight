#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m,a_sum=0;
  cin >> n >> m;
  vector <int> a(m);
  for(int i=0; i<m; i++){
    cin >> a.at(i);
    a_sum += a.at(i);
  }
  if(a_sum > n) cout << -1 << endl;
  else if(a_sum <= n) cout << n - a_sum << endl;
}