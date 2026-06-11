#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  int b = a/1.08;
  if(b*1.08==a){
    cout << b << endl;
  }
  else if((b+1)*108/100==a){
    cout << b+1 << endl;
  }
  else{
    cout << ":(" << endl;
  }

}