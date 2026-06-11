#include <bits/stdc++.h>
#include <limits>
#include <math.h>
#include <cmath>
#include <cctype>
#include <cstdio>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int> ;
using vs = vector<string>;
using vb = vector<bool>;
using vll = vector<long long>;
using vvll = vector<vector<long long >>;
#define PI  3.1415926535
#define rep(i, k, n) for(ll i = k; i < n; i++)

int main(){
  ll n, k; cin >> n >> k;
  vll res(n);
  rep(i, 0, n){cin >> res[i];}
  
  ll loop_start_village;
  ll loop_start_index;
  ll loop_cycle;
  
  vll village_index(0);
  vb num_check(n+1,false);
  
  village_index.emplace_back(1);
  num_check[1] = true;
  
  rep(i, 0, n){
    if(num_check[res[village_index[i]-1]]){
      loop_start_village = res[village_index[i]-1];
      break;
    }
    village_index.emplace_back(res[village_index[i]-1]);
    num_check[res[village_index[i]-1]] = true;
  }
  
  rep(i, 0, village_index.size()){
    if(village_index[i] == loop_start_village){
      loop_start_index = i;
      break;
    }
  }
  loop_cycle = village_index.size() - loop_start_index;
  
  //cout << loop_start_village << endl;
  //cout << loop_start_index << endl;
  //cout << loop_cycle << endl;
  
  if(k < village_index.size()){cout << village_index[k] << endl;}
  else{
    k -= loop_start_index;
    k %= loop_cycle;
    k += loop_start_index;
    cout << village_index[k] << endl;
  }
}

