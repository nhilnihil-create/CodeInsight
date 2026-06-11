#include <bits/stdc++.h>
using namespace std;

int main() {
  long long c = 100;
  long long x;
  cin >> x;
  
  long long count =0;
  
  for(long long i=0; i<1000000000000000000; i++){
    count++;
    c += c / 100;
    if(c >= x)
      break;
  }
  cout << count  << endl;
}
