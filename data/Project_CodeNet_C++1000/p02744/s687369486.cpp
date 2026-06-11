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
 
const ll inf = 1e9 + 7;
const ll Mod = 998244353;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

int N;
char ans[10];

int DFS(int turn, int cnt){
  if (turn == N){
    for (int i = 0; i < N; i++){
      printf("%c", ans[i]);
    }
    printf("\n");
    return 0;
  }

  for (int i = 0; i < cnt; i++){
    ans[turn] = 'a' + i;
    DFS(turn + 1, cnt);
  }
  
  ans[turn] = 'a' + cnt;
  DFS(turn + 1, cnt + 1);
  return 0;
}

int main(){
  cin >> N;
  DFS(0, 0);

  return 0;
}
