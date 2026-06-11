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

int N, K, C;
string S;

int cnt[int(2e5+5)][2];

int main(){
  cin >> N >> K >> C;
  cin >> S;

  int now = 0, day = 0;
  while (now < K){
    if (S[day] == 'o'){
      cnt[now][0] = day + 1;
      day += C+1; now++;
    }else{
      day++;
    }
  }
  now = K - 1; day = N - 1;
  while (now >= 0){
    if (S[day] == 'o'){
      cnt[now][1] = day + 1;
      day -= C+1; now--;
    }else{
      day--;
    }
  }


  for (int i = 0; i < K; i++){
    if (cnt[i][0] == cnt[i][1]) cout << cnt[i][0] << endl;
  }

  return 0;
}
