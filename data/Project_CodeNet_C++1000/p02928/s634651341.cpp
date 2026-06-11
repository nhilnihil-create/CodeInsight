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

ll N, K;
int A[2005];

int main(){
  scanf("%lld%lld", &N, &K);
  for (int i = 0; i < N; i++) scanf("%d", A + i);

  ll ans = 0;
  for (int i = 0; i < N; i++){
    ll a = 0, b = 0;
    for (int j = 0; j < i; j++){
      if (A[j] < A[i]) a++;
    }
    for (int j = i + 1; j < N; j++){
      if (A[i] > A[j]) b++;
    }
    ans += K * b; ans %= MOD;

    ll now = K * (K - 1) / 2; now %= MOD;
    now *= a + b; now %= MOD;
    ans += now; ans %= MOD;
  }
  printf("%lld\n", ans);

  return 0;
}
