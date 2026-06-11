#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n, m;
  cin >> n >> m;
  
  vector<int> vec(m);
  int total = 0;
  
  for(int i = 0; i < m; i++){
    int x;
    cin >> x;
    vec.at(i) = x;
    total += x;
  }
  
  if(total > n){
    cout << -1 << endl;
  }
  else if(total <= n){
    cout << n - total << endl;
  }
  
  
 
 
}

