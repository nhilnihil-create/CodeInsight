#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}

int main(){
  ll A,B;
  cin >> A >> B;
  ll p = gcd(A,B);
  ll ans = A/p*B;
  cout << ans  << endl;
}
