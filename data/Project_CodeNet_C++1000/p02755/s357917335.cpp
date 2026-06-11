#include <iostream>
#include <vector>
using namespace std;
using ll=long long ;
int main(){
  ll A,B;
  cin >> A >> B;
  for(ll i=0;i<1000000;i++){
  	ll eight=i*0.08;
    ll ten=i*0.10;
    if( eight == A && ten == B ){
    	cout << i << endl;
      return 0;
    }
  }
  cout << "-1" << endl;
  return 0;
}