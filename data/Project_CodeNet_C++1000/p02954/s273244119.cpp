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

int N, ans[int(1e5+5)];

int main(){
  string S; cin >> S;
  N = S.length();

  int R = 0;
  for (int i = 0; i < N; i++){
    if (S[i] == 'R') R++;
    else{
      ans[i-1] += (R+1) / 2;
      ans[i] += R/2;
      R = 0;
    }
  }

  int L = 0;
  for (int i = N - 1; i >= 0; i--){
    if (S[i] == 'L') L++;
    else{
      ans[i+1] += (L+1) / 2;
      ans[i] += L / 2;
      L = 0;
    }
  }

  cout << ans[0];
  for (int i = 1; i < N; i++) cout << " " << ans[i];
  cout << endl;


  return 0;
}
