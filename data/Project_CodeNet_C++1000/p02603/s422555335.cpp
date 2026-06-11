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
  ll stock = 0;      //現在の株の所持数

  for(int i=0; i<n-1; ++i) {
    if(a[i]<a[i+1]) {
      //買う処理
      stock = money/a[i];
      money = money%a[i];
      //売る処理
      money = money + stock*a[i+1];
      stock = 0;
    }
  }

  cout << money << endl;

  return 0;
}
