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
  ll x = 0;
  cin >> x;
  ll now = 0;
  for(int i = 0;i < n;i++){
    ll in = 0;
    cin >> in;
    now += in;
    if(now > x){
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << n + 1 << endl;
}