#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main(){
  int n;
  cin >> n;
  vector<int> p(n);
  vector<int> q(n);
  
  for(int i=0; i<n; i++) cin>> p[i], p[i]--;
  for(int i=0; i<n; i++) cin>> q[i], q[i]--;
  
  map<vector<int>, int> ord;
  int iter = 0;
  
  vector<int> v(n);
  for(int i=0; i<n; i++) v[i] = i;
  
  do {
    ord[v] = iter++;
  }while (next_permutation(v.begin(), v.end()));
  
  cout << abs(ord[p] - ord[q]) << endl;
  
  return 0;
}