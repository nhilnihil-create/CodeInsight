#include<iostream>
#include<cmath>
#define ll long long

using namespace std;

int main(void){
  ll N,K;
  cin >> N >> K;
  ll t = N % K;
  ll ans = min(t,abs(K-t));
  cout << ans << endl;
  return 0;
}