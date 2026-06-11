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

string S, T;
ll N, turn, ans, now = 0;
vector <ll> cnt[26];
int Now_Index[26];

int main(){
  cin >> S >> T;
  N = S.length();

  for (int i = 0; i < N; i++){
    cnt[S[i] - 'a'].push_back(i + 1);
  }

  for (int i = 0; i < T.length(); i++){
    int num = T[i] - 'a';
    if (cnt[num].size() == 0){
      printf("-1\n"); return 0;
    }
    
    int C = cnt[num].size();
    if (now >= cnt[num][C - 1]){
      turn++;
      fill(Now_Index, Now_Index + 26, 0);
      now = cnt[num][0];
      Now_Index[num] = 0;
    }else{
      for (int j = Now_Index[num]; j < C; j++){
        if (now < cnt[num][j]){
          now = cnt[num][j];
          Now_Index[num] = j + 1;
          break;
        }
      }

    } 
  }
  ans = N * turn + now;
  printf("%lld\n", ans);

  return 0;
}
