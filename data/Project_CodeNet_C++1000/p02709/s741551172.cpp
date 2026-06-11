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

int N;
ll A[int(2e3+5)], DP[int(2e3+5)][int(2e3+5)];
Pll P[int(2e3+5)];

int main(){
  scanf("%d", &N);
  for (int i = 1; i <= N; i++){
    scanf("%lld", A + i);
    P[i] = mp(A[i], i);
  }
  sort(P + 1, P + N + 1, greater<Pll>());

  ll ans = 0;
  for (ll i = 1; i <= N; i++){
    for (ll j = 0; j <= i; j++){
      ll now = 0;

      if (j >= 1){
        now = max(now, DP[j-1][i-j] + P[i].fi * abs(P[i].se - j));
      }
      if (i - j - 1 >= 0){
        now = max(now, DP[j][i-j-1] + P[i].fi * abs(P[i].se - (N - (i - j) + 1)));
      }
      DP[j][i-j] = now;
      ans = max(ans, DP[j][i - j]);
    }
  }
  printf("%lld\n", ans);

  return 0;
}
