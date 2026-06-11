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

int N, ans; string S;
char now[3];

int Judge(){
  int cnt = 0;
  for (int i = 0; i < N; i++){
    if (now[cnt] == S[i]) cnt++; 
    if (cnt == 3){
      ans++; return 0;
    }
  }
  return 0;
}

int Solve(int turn){
  if (turn == 3){
    Judge(); return 0;
  }

  for (char i = '0'; i <= '9'; i++){
    now[turn] = i;
    Solve(turn + 1);
  }
  return 0;
}

int main(){
  cin >> N >> S;
  Solve(0);
  cout << ans << endl;

  return 0;
}
