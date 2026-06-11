#include <bits/stdc++.h>
using namespace std;

int main(){
  long long a,b,c;
  cin >> a >> b >> c;
  long long x = 4*a*b;
  long long y = (c-a-b)*(c-a-b);
  if (c-a-b > 0 && x < y){
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
  

