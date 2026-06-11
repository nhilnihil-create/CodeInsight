#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#include <random>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){
  
  int n,k,c;
  string s;
  cin >> n >> k >> c >> s;
  vector<int> w;
  {
    int K = k;
    for(int i = 0;i < n;i++){
      if(s[i] == 'o'){
        K--;
        w.push_back(i+1);
        i += c;
      }
      if(K == 0)break;
    }
  }
  vector<int> v;
  {
    int K = k;
    for(int i = n-1;i >= 0;i--){
      if(s[i] == 'o'){
        K--;
        v.push_back(i+1);
        i -= c;
      }
      if(K == 0)break;
    }
  }
  reverse(ALL(v));
  rep(i,k)if(v[i] == w[i])cout << v[i] << "\n";
  
  


  

  return 0;
}