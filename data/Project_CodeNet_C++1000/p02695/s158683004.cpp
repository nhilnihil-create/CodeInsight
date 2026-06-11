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
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int N, M, Q;
int A[50], B[50], C[50], D[50];
int num[15], ans = 0;

int Solve(){
  int now = 0;
  for (int i = 0; i < Q; i++){
    if (num[B[i]] - num[A[i]] == C[i]) now += D[i];
  }
  ans = max(ans, now);

  return 0;
}

int Make(int res, int turn){
  if (turn == N){
    Solve();
    return 0;
  }
  for (int i = res; i <= M; i++){
    num[turn + 1] = i;
    Make(i, turn + 1);
  }
  return 0;
}

int main(){
  scanf("%d%d%d", &N, &M, &Q);
  for (int i = 0; i < Q; i++){
    scanf("%d%d%d%d", A + i, B + i, C + i, D + i);
  }
  Make(1, 0);
  printf("%d\n", ans);
  return 0;
}
