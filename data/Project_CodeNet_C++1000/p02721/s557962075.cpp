#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <complex>

using ll = long long int;
using namespace std;

int main(){
  // read problem
  ll N, K, C;
  string S;
  cin >> N >> K >> C >> S;

  // calculate dp1, dp2
  vector<ll> dp1(N), dp2(N);

  ll tmp_pos, tmp_count;

  tmp_pos = -C-1;
  tmp_count = 0;
  for(ll i = 0; i < N; i++){
    if(S[i] == 'o' && i > tmp_pos+C){
      tmp_count++;
      tmp_pos = i;
    }
    dp1[i] = tmp_count;
  }

  cerr << "dp1:" << endl;
  for(ll i = 0; i < N; i++){
    cerr << dp1[i] << " ";
  }cerr << endl;

  tmp_pos = N+C;
  tmp_count = 0;
  for(ll i = N-1; i >= 0; i--){
    if(S[i] == 'o' && i < tmp_pos-C){
      tmp_count++;
      tmp_pos = i;
    }
    dp2[i] = tmp_count;
  }

  cerr << "dp2: " << endl;
  for(ll i = 0; i < N; i++){
    cerr << dp2[i] << " ";
  }cerr << endl;

  // solve problem
  if(C == 0){
    ll count_o = 0;
    for(ll i = 0; i < N; i++){
      if(S[i] == 'o'){
        count_o++;
      }
      
    }
    if(count_o <= K){
      for(ll i = 0; i < N; i++){
        if(S[i] == 'o'){
          cout << i+1 << endl;
        }
      }
      return 0;
    }
    else{
      
      return 0;
    }
  }
  vector<ll> vac_list;
  if(N > C && dp2[C] >= K){
    vac_list.push_back(0);
  }
  for(ll i = 1; i < N-C; i++){
    if(dp1[i-1] + dp2[i+C] >= K){
      vac_list.push_back(i);
    }
  }
  if(N>C && dp1[N-C-1] >= K){
    vac_list.push_back(N-C);
  }

  ll nvac = vac_list.size();
  ll l, r, mid;

  cerr << "nvac: " << nvac << endl;
  for(ll i = 0; i < nvac; i++){
    cerr << vac_list[i] << " ";
  }cerr << endl;

  cerr << "Answer:" << endl;
  if(nvac == 0){
    for(long long int i = 0; i < N; i++){
      if(i != N-1 && dp2[i+1] >= K){
        continue;
      }
      if(i != 0 && dp1[i-1] >= K){
        continue;
      }
      cout << i+1 << endl;
    }
    return 0;
  }
  for(ll i = 0; i < N; i++){
    if(S[i] == 'x'){
      continue;
    }
    if(vac_list[0] > i){
      l = 0;
    }
    else if(vac_list[nvac-1] <= i){
      l = nvac-1;
    }
    else{
      l = 0;
      r = nvac-1;
      while(r-l>1){
        mid = (l+r)/2;
        if(vac_list[mid] <= i){
          l = mid;
        }
        else{
          r = mid;
        }
      }
    }
    l = vac_list[l];
    if(l <= i && l > i-C){
      continue;
    }
    if(i < N-1 && dp2[i+1] >= K){
      continue;
    }
    if(i != 0 && dp1[i-1] >= K){
      continue;
    }
    cout << i+1 << endl;
  }

  return 0;
}
