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

int N, M, S, T;
vector <int> Graph[int(1e5 + 5)];
int Dist[int(1e5 + 5)];
bool visited[int(1e5 + 5)][3];

int Solve(){
  priority_queue <Pii, vector<Pii>, greater<Pii> > que;
  que.push({0, S});

  while (!que.empty()){
    Pii Q = que.top(); que.pop();
    if (visited[Q.se][Q.fi % 3]) continue;
    visited[Q.se][Q.fi % 3] = true;

    if (Q.fi % 3 == 0) Dist[Q.se] = Q.fi / 3;

    for (int i = 0; i < Graph[Q.se].size(); i++){
      int next = Graph[Q.se][i];
      que.push({Q.fi + 1, next});
    }
  }
  printf("%d\n", Dist[T]);
  return 0;
}


int main(){
  scanf("%d%d", &N, &M);
  fill(Dist, Dist + N + 1, -1);
  for (int i = 0; i < M; i++){
    int U, V; scanf("%d%d", &U, &V);
    Graph[U].push_back(V);
  }
  scanf("%d%d", &S, &T);
  Solve();

  return 0;
}
