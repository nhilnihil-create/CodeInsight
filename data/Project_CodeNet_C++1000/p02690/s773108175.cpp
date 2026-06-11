#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  ll x;
  cin >> x;
  int ans_a,ans_b;
  for(ll a=-200;a<200;a++){
    for(ll b = -200;b<200;b++){
      ll m = pow(a,5);
      ll n = pow(b,5);
      if((m-n)==x) {
	cout << a << " " << b << endl;
	return 0;
      }
    }
  }
}
