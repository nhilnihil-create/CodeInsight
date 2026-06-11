#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;

int main() 
{
  int n;
  cin >> n;
  vector<double> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());

  double tmp = (v[0] + v[1])/2.0;
  for (int i = 2; i < n; i++){
    tmp = (tmp + v[i])/2.0;
  }
  cout << tmp << endl;
  return 0;
}
