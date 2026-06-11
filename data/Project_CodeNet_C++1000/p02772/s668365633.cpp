#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  bool ans = 1;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >> a.at(i);
  }
  for(int i=0;i<n;i++){
    if(a.at(i)%2 == 0 && a.at(i)%3 != 0 && a.at(i)%5 != 0){
      ans = 0;
      break;
    }
  }
  if(ans){
    cout << "APPROVED" << endl;
  }
  else{
    cout << "DENIED" << endl;
  }
}