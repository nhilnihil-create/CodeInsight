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
  int N; cin >> N;
  priority_queue <double, vector<double>, greater<double> > que;
  for (int i = 0; i < N; i++){
    double V; cin >> V;
    que.push(V);
  }

  while (!que.empty()){
    double Q1 = que.top(); que.pop();
    double Q2 = que.top(); que.pop();

    que.push((Q1 + Q2) / 2);

    if (que.size() == 1){
      cout << setprecision(16) << que.top() << endl;
      return 0;
    }
  }

  return 0;
}
