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
  ll n = 0;
  cin >> n;
  ll res = 0;
  res = pow(10,18);
  for(int i = 1;i <= sqrt(n);i++){
    if(n % i == 0){
      //cout << i << endl;
      res = min(res,i + n / i - 2);
    }
  }
  cout << res << endl;
}