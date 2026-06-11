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

int N, M;
char S[int(1e5 + 5)];
bool able[int(1e5 + 5)];
vector <int> ans;

int main(){
  scanf("%d%d", &N, &M);
  scanf("%s", S);

  int now = N;
  while (now > 0){
    bool flag = false;
    for (int i = M; i >= 1; i--){
      if (now - i < 0) continue;
      if (S[now - i] == '0'){
        flag = true;
        ans.push_back(i);
        now -= i;
        break;
      }
    }
    if (!flag){
      printf("-1\n"); return 0;
    }
  }
  
  printf("%d", ans[ans.size() - 1]);
  for (int i = ans.size() - 2; i >= 0; i--){
    printf(" %d", ans[i]);
  }
  printf("\n");

  return 0;
}
