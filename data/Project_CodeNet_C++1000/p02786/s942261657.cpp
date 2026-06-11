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

ll atack(ll x){
  if(x == 1){
    return 1;
  }else{
    ll t = atack(x/2);
    return t*2 + 1;
  }
}

int main(){
   ll N;
   cin >> N;
   cout << atack(N) << endl;

}
