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
ll A[505], sum;
vector <ll> P;

int Prepare(){
  scanf("%d%lld", &N, &K);
  for (int i = 0; i < N; i++){
    scanf("%lld", A + i);
    sum += A[i];
  }
  for (ll i = 1; i * i <= sum; i++){
    if (sum % i != 0) continue;
    P.push_back(i); P.push_back(sum / i);
  }
  sort(P.begin(), P.end());
  return 0;
}

ll ans = 0, now[int(500)];
int Solve(ll num){
  ll cnt = 0;
  for (int i = 0; i < N; i++) now[i] = A[i] % num;
  sort(now, now + N);

  int R = N - 1;
  for (int i = 0; i < N; i++){
    if (now[i] % num == 0) continue;
    cnt += now[i];

    while (now[i] > 0){
      if (now[i] + now[R] >= num){
        now[i] -= num - now[R];
        now[R] = num;
        R--;
      }else{
        now[R] += now[i]; now[i] = 0;
      }
    }
  }

  if (cnt <= K) ans = max(ans, num);

  return 0;
}

int main(){
  Prepare();
  for (int i = 0; i < P.size(); i++) Solve(P[i]);
  cout << ans << endl;

  return 0;
}
