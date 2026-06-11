#include<bits/stdc++.h>
using namespace std;
//using long long = ll;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> A(n,0);
  for(int i = 0; i < n; i++) cin >> A.at(i);
  
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  
  int votes = 0;
  for(int i = 0; i < n; i++) votes += A.at(i);
  int judge;
  if(votes % (4*m) == 0 ) judge = votes/(4*m);
  else judge = votes/(4*m) + 1;
  
  bool ok = true;
  for(int i = 0; i < m; i++){
    if(A.at(i) < judge) ok = false;
  }
  
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}