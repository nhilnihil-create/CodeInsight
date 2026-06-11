#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  for(int i = 0; i < n; i++){
    cin >> d.at(i);
  }
  
  n /= 2;
  sort(d.begin(), d.end());
  int a = d.at(n-1);
  int b = d.at(n);
  
  int counta = 0;
  int countb = 0;
  
  for(int i = 0; i < 2 * n; i++){
    if(d.at(i) < a + 1){
      counta++;
    }
    if(d.at(i) >= b){
      countb++;
    }
  }
  
  if(counta == countb){
    cout << b-a << endl;
  }
  else{
    cout << 0 << endl;
  }
}
