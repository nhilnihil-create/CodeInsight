#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {

  ll n;
  ll a[100];
  cin >> n;
  for(int i=0; i<n; ++i) cin >> a[i];

  ll money = 1000;   //所持金

  for(int i=0; i<n-1; ++i) {
    ll stock = 0;
    if(a[i]<a[i+1]) {
      stock = money/a[i];
      money += (a[i+1]-a[i])*stock;
    }
  }

  cout << money << endl;

  return 0;
}
