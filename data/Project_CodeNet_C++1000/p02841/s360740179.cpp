#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <cstdlib>
#include <deque>

using namespace std;
const long long P = 1000000007;

int bubblesort(int a[],int n) {
  int sw = 0;
  bool flag = 1;
  for(int i = 0; flag; i++) {
    flag = 0;
    for(int j = n-1; j >= i+1; j--) {
      if(a[j] < a[j-1]) {
        swap(a[j],a[j-1]);
        flag = 1;
        sw++;
      }
    }
  }
  return sw;
}

int main() {
  int m1,d1,m2,d2;
  cin >> m1 >> d1 >> m2 >> d2;
  if(d2 == 1 && m2-m1 == 1) {
    cout << '1' << endl;
  }else {
    cout << '0' << endl;
  }
  return 0;
}