//g++ -std=gnu++14 a.cpp

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <tuple>
#include <iomanip>
#include <random>
#include <math.h>
#include <stdio.h>

using namespace std;

#define ll long long
#define rep(i, n) for(ll i = 0; i < (n); i++)
ll MOD = 1e9 + 7;
int INF = 1 << 30;
ll INFL = 1LL << 60;

ll MODP = 998244353;


int main(){
  int N;
  cin >> N;
  vector<vector<pair<int,int>>> A(N);
  rep(i,N){
    int a;
    cin >> a;
    rep(j,a){
      int m,n;
      cin >> m >> n;
      A[i].push_back(make_pair(m,n));
    }
  }

  int ans = 0;
  int ad = 1;
  rep(i,N)ad *= 2;
  int ma = ad-1;

  for(int bit = 0;bit <= ma;bit++){
    vector<int> torf(N);
    for(int i = 0;i < N;i++){
      if(bit >> i & 1)torf[i] = 1;
      else torf[i] = 0;
    }
    bool hantei = true;
    rep(k,N){
      if(torf[k]){
        for(auto x : A[k]){
          if(torf[x.first - 1] != x.second){
            hantei = false;
            break;
          }
        }
      }
    }

    if(hantei){
      int add = 0;
      rep(k,N)if(torf[k] == 1)add++;
      ans = max(ans,add);
    }
  }
  cout << ans << endl;


  return 0;
}
