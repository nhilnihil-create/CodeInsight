#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  long long n,k;
  cin >> n;
  long long d[n];
  
  for(int i = 0; i < n; i++) {
    cin >> d[i];
  }
  sort(d,d+n);

  long long low,high;
  low = d[n/2-1];
  high = d[n/2];
  cout << high - low << endl;
  return 0;
}
