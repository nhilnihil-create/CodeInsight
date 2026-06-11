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

int N, M, ans;
Pii P[int(1e5 + 5)];
priority_queue <int> que;

int main(){
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++){
    int A, B; scanf("%d%d", &A, &B);
    P[i] = {A, B};
  }
  sort(P, P + N);

  int now = 0;
  que.push(0);
  for (int i = 1; i <= M; i++){
    for (int j = now; j < N; j++){
      if (P[j].fi <= i){
        que.push(P[j].se); now++;
      }else break;
    }
    ans += que.top();
    if (que.top() > 0) que.pop();
  }
  cout << ans << endl;

  return 0;
}
