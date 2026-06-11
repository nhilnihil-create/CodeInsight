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

int N; ll K;
int A[int(2e5 + 5)];
ll Bit[61];
int Table[61][int(2e5 + 5)];

int main(){
  Bit[0] = 1;
  for (int i = 1; i < 61; i++) Bit[i] = Bit[i-1] * 2;

  scanf("%d%lld", &N, &K);
  for (int i = 1; i <= N; i++) {
    scanf("%d", A + i);
    Table[0][i] = A[i];
  }

  for (int i = 1; i < 61; i++){
    for (int j = 1; j <= N; j++){
      int next = Table[i - 1][j];
      Table[i][j] = Table[i - 1][next];
    }
  }

  int now = 1;
  while (K > 0){
    for (int i = 0; i < 60; i++){
      if (K == Bit[i]){
        now = Table[i][now];
        K -= Bit[i];
        break;
      }
      if (K < Bit[i + 1]){
        now = Table[i][now];
        K -= Bit[i];
        break;
      }
    }
  }
  cout << now << endl;

  return 0;
}
