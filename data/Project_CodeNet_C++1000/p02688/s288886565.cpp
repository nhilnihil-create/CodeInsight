#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k, d, a;
  cin >> n >> k;
  vector<bool> A(n, false);
  
  for(int i = 0; i < k; i++){
    cin >> d;
    for(int j = 0; j < d; j++){
      cin >> a;
      A.at(a - 1) = true;
    }
  }
  int count = 0;
  for(int i = 0; i < n; i++){
    if(!A.at(i)) count++;
  }
  
  cout << count << endl;
  
}