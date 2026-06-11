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
  ll a,b;
  cin >> a >> b;
  ll res = (b - 1) / (a - 1);
  if((b - 1) % (a - 1) != 0)res++;
  cout << res << endl;
}
