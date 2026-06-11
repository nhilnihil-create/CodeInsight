#include <bits/stdc++.h>
using namespace std;  

int main() {
  string n;
  cin >> n;
  
  int N = n.size();
  int sum = 0;
  for(int i = 0; i < N; i++){
    int num = (int)n.at(i) - 48;
    sum += num;
  }
  
  if(sum % 9 == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}