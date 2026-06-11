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

int N, M, DP[int(1e5 + 5)];
char S[int(1e5 + 5)];

int main(){
  scanf("%d%d", &N, &M);
  scanf("%s", S);

  fill(DP, DP + N + 1, 1e9);
  DP[0] = 0;
  priority_queue <int> que; que.push(0);

  while (!que.empty() && DP[N] == 1e9){
    int Q = que.top(); que.pop();
    for (int i = 1; i <= M; i++){
      int next = Q + i;
      if (next > N) continue;
      if (S[next] == '1') continue;
      if (DP[next] != 1e9) continue;
      que.push(next);
      DP[next] = DP[Q] + 1;
    }
  }

  if (DP[N] == 1e9){
    printf("-1\n"); return 0;
  }

  vector <int> ans;
  int now = N;
  while (now > 0){
    for (int i = M; i >= 1; i--){
      if (now - i < 0) continue;
      if (DP[now] == DP[now - i] + 1){
        now -= i;
        ans.push_back(i);
        break;
      }
    }
  }

  printf("%d", ans[ans.size() - 1]);
  for (int i = ans.size() - 2; i >= 0; i--){
    printf(" %d", ans[i]);
  }
  printf("\n");

  return 0;
}
