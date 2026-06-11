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

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int N;
ll A[int(3e5 + 5)];

ll Bit[62], cnt0[62], cnt1[62];

int main(){
  Bit[0] = 1;
  for (int i = 1; i < 62; i++){
    Bit[i] = Bit[i-1] * 2;
    Bit[i] %= MOD;
  }

  scanf("%d", &N);
  for (int i = 0; i < N; i++){
    scanf("%lld", A + i);

    ll num = A[i];
    for (int j = 0; j < 62; j++){
      if (num % 2 == 0) cnt0[j]++;
      else cnt1[j]++;
      num /= 2;
    }
  }

  ll ans = 0;
  for (int i = 0; i < 62; i++){
    ll now = cnt0[i] * cnt1[i] % MOD;
    ans += Bit[i] * now;
    ans %= MOD;
  }
  printf("%lld\n", ans);

  return 0;
}
