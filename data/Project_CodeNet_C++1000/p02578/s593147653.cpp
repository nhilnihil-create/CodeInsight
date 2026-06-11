#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ll n, num, prenum;
  ll h = 0;
  cin >> n;
  cin >> num;
  n--;
  prenum = num;
  while(n--) {
  	cin >> num;
    if(num < prenum) {
    	h += prenum-num;
      num = prenum;
    }
    prenum = num;
  }
  cout << h;
	return 0;
}