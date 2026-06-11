#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
  int n;
  cin >>n;
  double a,b;
  b =0;
  for(int i=0 ; i<n ; i++){
    cin >>a;
    b = b + 1/a;
  }
  cout <<1/b <<endl;
}