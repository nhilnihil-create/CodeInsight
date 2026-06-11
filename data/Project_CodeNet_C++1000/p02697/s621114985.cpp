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
  ll n,m;
  cin >> n >> m;
  ll ok = 0;
  if(n % 2 == 1)/*n--,*/ok = 1;
  vector<ll> a(m + 2);
  vector<ll> b(m + 2);
  for(int i = 0;i < m + 2;i++)a[i] = i + 1;
  ll num = 0;
  if(ok == 0)num = 1;
  for(int i = 0;i < m + 2;i++){
    if(i >= m / 2 && ok == 0)num = 2;
    b[i] = n - i - num;
  }
  int pu = 0;
  for(int i = 0;i < m + pu;i++){
    if(n % 2 == 1 || abs(a[i] - b[i]) != n / 2)cout << a[i] << " " << b[i] << endl;
    else pu++;
  }
  return 0;
}

