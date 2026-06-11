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
  int n;
  cin >> n;
  cout << fixed << setprecision(15) << ceill(n / 2.0) / n;
}
