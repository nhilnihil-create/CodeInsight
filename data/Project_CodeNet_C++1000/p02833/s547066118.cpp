#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  ll N;
  cin >> N;
  ll ans = 0;
  ll sum = 10;
  if(N%2==0){
    ll i=1;
    while(N>=pow(5,i)*2){
      ans += N/sum;
      sum *= 5;
      i++;
    }
  }
  cout << ans << endl;
}
