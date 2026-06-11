#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(void){
  ll x,k,d;
  cin >> x >> k >> d;
  if (abs(x)/d > k) {
    cout << abs(x)-d*k << endl;
  }
  else{
    k-=abs(x)/d;
    x = abs(x)-d*(abs(x)/d);
    cout << abs(x-d*(k%2)) << endl;
  }
}