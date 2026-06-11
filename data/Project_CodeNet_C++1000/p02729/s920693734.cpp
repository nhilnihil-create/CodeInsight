#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m, c = 0;
  cin >> n >> m;
  if(!(n <= 1)){
    c += n*(n - 1)/2;
  }
  if(!(m <= 1)){
    c += m*(m - 1)/2;
  }
  cout << c << endl;
}