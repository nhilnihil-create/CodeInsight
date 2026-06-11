//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <time.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
 
const ll nmax = 1e9 + 7;
const ll Mod = 998244353;
const double PI = 2 * asin(1);


int main(){
  string S; cin >> S;
  ll K; cin >> K;

  if (S.length() == 1){
    cout << K / 2 << endl;
    return 0;
  }

  vector <ll> Count;
  ll now = 1;
  for (int i = 1; i < S.length(); i++){
    if (S[i] == S[i - 1]){
      now++;
    }else{
      Count.push_back(now);
      now = 1;
    }
  }
  if (now > 1) Count.push_back(now);


  if (Count.size() == 1){
    cout << Count[0] * K / 2 << endl;
    return 0;
  }
  ll ans = 0;
  for (int i = 0; i < Count.size(); i++){
    ans += Count[i] / 2;
  }
  ans *= K;

  if (S[0] == S[S.length() - 1] && Count[0] % 2 != 0 && Count[Count.size() - 1] % 2 != 0){
    ans += K - 1;
  }
  cout << ans << endl;
  
  

  return 0;
}