#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#define REP(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

int main() {
  vector<int> a(250000, 1);
  a[0] = a[1] = 0;
  for(int i = 2;i*i < 250000; ++i)
    if (a[i])
      for(int j = i*i; j < 250000; j+=i)
        a[j] = 0;
  vector<int> b(124000);
  int sum = 0;
  for (int i = 1; i < 124000; ++i) {
    sum += a[2*i] + a[2*i-1];
    sum -= a[i];
    b[i] = sum;
  }
  while(1) {
    int n;
    cin >> n;
    if(!n) break;
    cout << b[n] << endl;
  }
  return 0;
}