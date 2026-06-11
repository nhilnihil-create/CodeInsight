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


int main(){
  int K; cin >> K;
  queue <ll> que;
  for (int i = 1; i <= 9; i++) que.push(i);

  for (int i = 0; i < K - 1; i++){
    ll Q = que.front(); que.pop();

    if (Q % 10 > 0){
      que.push(Q * 10 + Q % 10 - 1);
    }
    que.push(Q * 10 + Q % 10);
    if (Q % 10 < 9){
      que.push(Q * 10 + Q % 10 + 1);
    }
  }
  cout << que.front() << endl;

  return 0;
}
