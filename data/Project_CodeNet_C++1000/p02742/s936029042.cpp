#include<bits/stdc++.h>
using namespace std;

int main(){
  long long a, b;
  cin >> a >> b;
  long long x = a * b;
  if(a == 1 || b == 1){
    cout << 1 << endl;
    return 0;
  }
  
  if(x % 2 == 0){ //割り切れるとき
    cout << x / 2 << endl;
  }
  else cout << x / 2 + 1 << endl;
}