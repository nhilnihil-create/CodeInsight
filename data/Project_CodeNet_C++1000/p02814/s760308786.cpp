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

ll GCD(ll a, ll b){
  if (a > b) swap(a, b);
  while (a % b != 0) a %= b, swap(a, b);
  return b;
}

ll LCM(ll a, ll b){
  ll G = GCD(a, b);
  return a / G * b;
}

int N;
ll M, A[int(1e5 + 5)], cnt[int(1e5 + 5)];

int Count(){
  for (int i = 0; i < N; i++){
    ll now = A[i];
    while (now % 2 == 0){
      now /= 2; cnt[i]++;
    }
  }
  return 0;
}

int main(){
  scanf("%d%lld", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%lld", A + i); A[i] /= 2;
  }

  Count();
  for (int i = 1; i < N; i++){
    if (cnt[i] != cnt[i - 1]){
      cout << 0 << endl; return 0;
    }
  }

  ll now = 1;
  for (int i = 0; i < N; i++){
    now = LCM(now, A[i]);
    if (now > M){
      cout << 0 << endl; return 0;
    }
  }

  ll ans = M / now - M / (2 * now);
  cout << ans << endl;


  return 0;
}
