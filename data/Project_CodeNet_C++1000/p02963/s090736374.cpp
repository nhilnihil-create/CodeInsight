#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
using namespace std;
typedef long long ll;
int main(){
  ll n = 0;
  cin >> n;
  int num = 0;
  num = pow(10,9);
  int a = 0;
  a = (num - n % num) % num;
  int b = 0;
  b = (n + a) / num;
  cout << 0 << " " << 0 << " " << (int)pow(10,9) << " " << 1 << " " << a << " " << b << endl;
  return 0;
}