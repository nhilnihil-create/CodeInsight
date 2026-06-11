#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

int main(){
  ll N;
  cin >> N;
  vector<ll> a(N);
  for(ll i=0;i<N;++i){
    cin >> a.at(i);
    --a.at(i);
  }

  ll index=0;
  ll N_break=0;
  for(ll i=0;i<N;++i){
    if(a.at(i)==index){
      ++index;
      continue;
    }
    ++N_break;
    if(N_break==N) break;
  }

  if(N_break==N) cout << -1 << endl;
  else cout << N_break << endl;

  return 0;
}
