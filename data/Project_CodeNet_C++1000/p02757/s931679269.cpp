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
#include <stdio.h>
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

#define fi first
#define se second
#define mp make_pair
 
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll INF = 1ll << 60;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int N, P; string S;
ll dig[int(2e5 + 5)], DP[int(1e4 + 5)];

int Exception(){
  ll ans = 0;
  for (ll i = N - 1; i >= 0; i--){
    int now = S[i] - '0';
    if (now % P == 0) ans += i + 1;
  }
  cout << ans << endl;
  return 0;
}

int main(){
  cin >> N >> P >> S;
  if (P == 2 || P == 5){
    Exception(); return 0;
  }
  ll ten = 1;
  for (int i = N - 1; i >= 0; i--){
    dig[i] = (S[i] - '0') * ten % P;
    ten *= 10; ten %= P;
  }

  ll now = 0;
  for (int i = N; i >= 0; i--){
    now += dig[i]; now %= P;
    DP[now]++;
  }
  
  ll ans = 0;
  for (int i = 0; i < P; i++){
    ans += DP[i] * (DP[i] - 1) / 2;
  }
  cout << ans << endl;

  return 0;
}
