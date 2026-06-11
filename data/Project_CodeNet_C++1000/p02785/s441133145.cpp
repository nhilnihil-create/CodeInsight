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

int main(){
   ll N,K;
   cin >> N >> K;
   vector<ll> H(N);
   rep(i,N)cin >> H[i];
   sort(H.begin(),H.end());
   if(K >= N)cout << 0 << endl;
   else{
     ll ans = 0;
     rep(i,N-K)ans += H[i];
     cout << ans << endl;
   }
}
