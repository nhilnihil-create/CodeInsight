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
string S;
ll cnt[2019];

int main(){
  cin >> S; N = S.length();
  cnt[0]++;

  int now = 0, ten = 1;
  for (int i = N - 1; i >= 0; i--){
    now += (S[i] - '0') * ten;
    now %= 2019;
    cnt[now]++;
    ten *= 10; ten %= 2019;
  }

  ll ans = 0;
  for (int i = 0; i < 2019; i++){
    ans += cnt[i] * (cnt[i] - 1) / 2;
  }
  cout << ans << endl;

  return 0;
}
