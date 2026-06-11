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

int N, A[int(1e5 + 5)];
Pil P[int(1e5 + 5)];
multiset <ll> st = {0, 0};

int main(){
  scanf("%d", &N);
  st.insert(N + 1);
  st.insert(N + 1);

  for (int i = 1; i <= N; i++){
    scanf("%d", A + i);
    P[i] = {A[i], i};
  }
  sort(P + 1, P + N + 1, greater<Pil>());
  st.insert(P[1].se);

  ll ans = 0;
  for (int i = 2; i <= N; i++){
    ll now = P[i].se; st.insert(now);

    auto L1 = st.find(now); L1--;
    auto L2 = st.find(now); L2--; L2--;

    auto R1 = st.find(now); R1++;
    auto R2 = st.find(now); R2++; R2++;

    ll sum = (*L1 - *L2) * (*R1 - now);
    sum += (*R2 - *R1) * (now - *L1);

    ans += ll(P[i].fi) * sum;
  }
  cout << ans << endl;


  return 0;
}
