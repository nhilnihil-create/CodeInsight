#include<iostream>
#define ll long long

using namespace std;

int main(){
  ll n,a,b;
  cin >> n >> a >> b;
  ll d = n/(a+b);
  if(n % (a+b) >= 0 && n % (a+b) <= a) cout << d*a + n % (a + b) << endl;
  else if(n % (a+b) > a) cout << (d+1)*a << endl;
  return 0;
}