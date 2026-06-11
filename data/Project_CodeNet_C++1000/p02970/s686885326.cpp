#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
  int n, d;
  cin >> n >> d;
  
  int one = 2*d+1;
  
  if (n%one == 0)
    cout << n/one << endl;
  else
    cout << n/one + 1 << endl;
}