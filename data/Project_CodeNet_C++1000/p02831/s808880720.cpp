#include<iostream>
#include<algorithm>
using namespace std;

template< typename T >
T extgcd(T a, T b, T &x, T &y) {
  T d = a;
  if(b != 0) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}

int main(){
    long long int a, b;
    cin >> a >> b;
    long long int x, y;
    long long int ans = a / extgcd(a, b, x, y);
    ans *= b;
    cout << ans << endl;
    return 0;
}