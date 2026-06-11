#include <bits/stdc++.h>
using namespace std;

int main(){
  int payment;
  cin >> payment;

  int items= payment/ 100;
  int under100= payment% 100;
  
  bool ans= (under100 <= 5*items);

  cout << ans << endl;
}