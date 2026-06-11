#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;
const ll max_N = 9*pow(10,6)+1;

int main(){
  ll K;
  cin >> K;
  if(K%2==0 || K%5==0) cout << "-1" << endl;
  else{
    ll L=9*K;
    if(K%7==0) L /= 7;
    ll ans = 1;
    ll j = 0;
    bool fla = false;
    for(ll i=0;i<max_N;i++){
      ans = ans*10%(L);
      j++;
      if(ans==1){
	fla = true;
	break;
      }
    }
    if(fla) cout << j << endl;
    else cout << "-1" << endl;
  }
}
