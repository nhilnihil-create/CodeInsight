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
ll A[int(2e5 + 5)], B[int(2e5 + 5)];
priority_queue <Pli> que;

int main(){
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%lld", A + i);
  for (int i = 0; i < N; i++){
    scanf("%lld", B + i);
    que.push({B[i], i});
  }

  ll ans = 0;
  while (!que.empty()){
    Pli Q = que.top(); que.pop();
    int now = Q.se; ll sum = 0;

    if (B[now] == A[now]) continue;

    if (now == 0) sum = B[N - 1] + B[1];
    else if (now == N - 1) sum = B[N - 2] + B[0];
    else sum = B[now - 1] + B[now + 1];

    if (sum >= B[now]){
      printf("-1\n"); return 0;
    }

    ll turn;
    if (A[now] >= sum){
      turn = (B[now] - A[now]) / sum;
    }else{
      turn = (B[now] / sum);
      if (B[now] % sum == 0) turn--;
    }

    ans += turn;
    B[now] -= turn * sum;

    if (turn <= 0){
      printf("-1\n"); return 0;
    }

    if (A[now] == B[now]) continue;
    if (A[now] > B[now]){
      printf("-1\n"); return 0;
    }
    que.push({B[now], now});
  }
  printf("%lld\n", ans);

  return 0;
}
