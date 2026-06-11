//g++ -std=gnu++14 a.cpp
//#include <bits/stdc++.h>

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

using namespace std;

#define ll long long
#define rep(i, n) for(ll i = 0; i < (n); i++)
ll MOD = 1e9 + 7;
int INF = 1 << 30;
ll INFL = 1LL << 60;

int count(int x,int y,int n){
  int res = 0;
  for(int i = 1;i <= n;i++){
    //int a = int(to_string(i).at(0)) - int('0');
    int b = i%10;
    if(b == y){
      int a = i;
      while(a/10 > 0){
        a /= 10;
      }
      if(a == x)res++;
    }
  }
  return res;
}

int main(){
  int N;
  cin >> N;
  int ans = 0;

  for(int i = 0;i <= 9;i++){
    for(int j = 0;j <= 9;j++){
      int a = count(i,j,N);
      int b = count(j,i,N);
      ans += a*b;
    }
  }
  cout << ans << endl;
}
