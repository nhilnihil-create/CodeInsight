#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a,b;
  cin >> a >> b;
  
    if((a%2==0 && b%2==0) || (a%2==1 && b%2==1)){
    cout << (a+b)/2 << endl;
  }
  else{
    cout << "IMPOSSIBLE" << endl;
  }
  
}