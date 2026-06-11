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

string S;
ll DP[int(1e5+5)][13];
int main(){
  cin >> S;
  DP[0][0] = 1;

  for (int i = 1; i <= S.length(); i++){
    if (S[i-1] != '?'){
      int num = S[i-1] - '0';
      for (int j = 0; j < 13; j++){
        DP[i][(j*10+num)%13] += DP[i-1][j];
        DP[i][(j*10+num)%13] %= MOD;
      }
    }else{
      for (int num = 0; num <= 9; num++){
        for (int j = 0; j < 13; j++){
          DP[i][(j*10+num)%13] += DP[i-1][j];
          DP[i][(j*10+num)%13] %= MOD;
        }
      }
    }
  }
  cout << DP[S.length()][5] << endl;

  return 0;
}
