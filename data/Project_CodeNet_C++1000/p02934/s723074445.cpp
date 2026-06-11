#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
  ll n;
  cin >> n;
  double res = 0;
  for(int i = 0;i < n;i++){
    ll in;
    cin >> in;
    res += (double)1 / in;
  }
  res = 1 / res;
  cout << fixed << setprecision(10) << res << endl;
}