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
  ll a[N];
  for(ll i=0;i<N;i++){
    cin >> a[i];
  }
  ll j = 1;
  bool go = false;
  for(ll i=0;i<N;i++){
    if(a[i]==j){
      j++;
      go = true;
    } 
  }
  if(go) cout << N-j+1 << endl;
  else cout << -1 << endl;
}
