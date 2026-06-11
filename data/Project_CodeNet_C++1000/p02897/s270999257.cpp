#include<bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  
  double p = 0;
  if(n%2==0) p = 0.5;
  else {
    double x = n;
    p = (x+1)/(2 * x);
  }
  cout << p << endl;
}
