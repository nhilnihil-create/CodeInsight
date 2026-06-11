#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int N, M;
  cin >> N >> M;
  vector <int> ac(N), pena(N);
  rep(i,M){
    int p;
    string s;
    cin >> p >> s;
    p--;  //0-indexedに直す
    if (ac[p]) continue;
    if (s == "AC"){
      ac[p] = 1;
    }else{
      pena[p] ++;
    }
  }
  int AC = accumulate(ac.begin(), ac.end(), 0);
  int PENA = 0;
  rep(i,N){
    if (ac[i]) PENA += pena[i];
  }
  cout << AC << " " << PENA << endl;
  return 0;
}
