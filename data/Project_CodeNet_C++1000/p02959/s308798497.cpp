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
ll A[int(1e5 + 5)], B[int(1e5 + 5)];

int main(){
  scanf("%d", &N);
  for (int i = 0; i <= N; i++) scanf("%lld", A + i);
  for (int i = 0; i < N; i++) scanf("%lld", B + i);

  ll ans = 0;
  for (int i = 0; i < N; i++){
    if (B[i] < A[i]){
      ans += B[i]; A[i] -= B[i];
      B[i] = 0;
    }else{
      ans += A[i]; B[i] -= A[i];
      if (B[i] < A[i + 1]){
        ans += B[i]; A[i + 1] -= B[i];
      }else{
        ans += A[i + 1]; A[i + 1] = 0;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
