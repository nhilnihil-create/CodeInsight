#include <bits/stdc++.h>

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
vector <ll> used;
ll A[int(1e5+5)];
map <ll, int> cnt;

int main(){
  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> A[i];
    if (cnt[A[i]] == 0) used.push_back(A[i]);
    cnt[A[i]]++;
  }

  if (used.size() > 3){
    No(); return 0;
  }
  if (used.size() == 1){
    if (used[0] == 0) Yes();
    else No();
    return 0;
  }
  if (N % 3 != 0){
    No(); return 0;
  }
  if (used.size() == 2){
    if (cnt[0] * 3 == N) Yes();
    else No();
    return 0;
  }

  ll res = 0;
  for (int i = 0; i < 3; i++){
    res ^= used[i];
    if (cnt[used[i]] * 3 != N){
      No(); return 0;
    }
  }
  if (res == 0) Yes();
  else No();

  return 0;
}
