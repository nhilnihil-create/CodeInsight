#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <algorithm>

typedef long long ll;
typedef long double ld;

using namespace std;
int main()
{
  int a, b;
  cin >> a >> b;
  if (a <= b * 2)
  {
    cout << "0";
    return 0;
  }
  cout << a - b * 2;
}
