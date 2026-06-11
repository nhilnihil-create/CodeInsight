#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;
int main() {
  int x;
  int count = 1;
  cin >> x;
  while(1) {
    if (!((x*count)%360)) break;
    count++;
  }
  cout << count << endl;
}