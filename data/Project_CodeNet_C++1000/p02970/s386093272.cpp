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
  ll n,d;
  cin >> n >> d;
  d *= 2,d++;
  ll res = n / d;
  if(n % d != 0)res++;
  cout << res << endl;
}
