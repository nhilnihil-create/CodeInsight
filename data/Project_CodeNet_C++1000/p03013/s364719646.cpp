
#include <bits/stdc++.h>

#define loop(s, e, i) for (int i=s; i<e; ++i)
#define print(s) cout << s << endl;
using namespace std;
using ll = long long;

#define DIV 1000000007
 
int main() {

  ll N, M;
  cin >> N >> M;
  vector<ll> NUM(N+1);

  loop(0, M, i) {
    int tmp;
    cin >> tmp;
    tmp;
    NUM[tmp] = -1;
  }

  if (NUM[1] != -1) {
    NUM[1] = 1;
  }
  NUM[0] = 1;


  loop(2, N+1, i) {
    if (NUM[i] == -1) {
      continue;
    }
    ll n1 = NUM[i-1];
    ll n2 = NUM[i-2];
    if (n1 == -1) n1 = 0;
    if (n2 == -1) n2 = 0;
    NUM[i] = (n1+n2) % DIV;
  }
  print(NUM[N]);
}