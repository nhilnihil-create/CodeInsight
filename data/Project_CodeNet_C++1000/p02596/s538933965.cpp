#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(void){
  ll k;
  cin >> k;

  ll m=0;
  ll a=1;
  int i=1;

  while (i<=k){
    m+=(7*a);
    m%=k;
    if (m==0) {
      cout << i << endl;
	  return 0;
    }
    a*=10;
    a%=k;
    i++;
  }
  cout << -1 << endl;
}
