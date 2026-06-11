#include <bits/stdc++.h>
using namespace std;

int main() {
  long long x, a = 100, count = 0;
  cin >> x; 
  
  for(int i = 1; ;i++){
      a += a * 1 / 100;
      count++;
    if(a >= x)
      break;
  }
  cout << count << endl;
}
