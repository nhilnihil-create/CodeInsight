#include<iostream>
#include<cmath>
#define ll long long int

using namespace std;

int main(void){
  ll a,b,n;
  cin >> a >> b >> n;
  
  cout << floor(a*min(b-1,n)/b) << endl;
  
  return 0;
}