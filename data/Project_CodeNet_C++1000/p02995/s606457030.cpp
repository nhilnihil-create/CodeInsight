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
ll gcd(ll a,ll b){
  if(a % b == 0)return b;
  else{
     return(gcd(b,a% b));
  }
}
int main(){
  ll a,b,c,d;
  cin >> a >> b >> c >> d;
  ll res = 0;
  res = b - b / c - b / d + b / (c / gcd(c,d) * d);
  //cout << res << endl;
  res -= (a - 1) - (a - 1) / c - (a - 1) / d + (a - 1) / (c / gcd(c,d) * d);
  cout << res << endl;
}