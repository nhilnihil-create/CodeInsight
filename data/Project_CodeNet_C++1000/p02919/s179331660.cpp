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

ll N;
Pll P[int(1e5 + 5)];

int main(){
  scanf("%lld", &N);
  multiset <ll> mst = {0, 0, N+1, N+1};
  for (ll i = 0; i < N; i++){
    scanf("%lld", &P[i].fi);
    P[i].se = i + 1;
  }
  sort(P, P + N, greater<Pll>());

  ll ans = 0;
  for (int i = 0; i < N; i++){
    mst.insert(P[i].se);
    auto iter1 = mst.find(P[i].se);
    auto iter2 = iter1;

    iter1--; ll L1 = *iter1;
    iter1--; ll L2 = *iter1;

    iter2++; ll R1 = *iter2;
    iter2++; ll R2 = *iter2;

    ll cnt = (L1-L2) * (R1-P[i].se) + (P[i].se-L1) * (R2-R1);
    ans += cnt * P[i].fi;
  }
  cout << ans << endl;

  return 0;
}
