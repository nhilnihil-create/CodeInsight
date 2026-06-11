#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> H(N);
  rep(i, N) cin >> H.at(i);
  vector<set<int>> A(N);
  int x, y;
  rep(i, M){
   cin >> x >> y;
   A.at(x-1).insert(y-1);
   A.at(y-1).insert(x-1);
  }
  
  int ans = 0;
  
  rep(i, N){
   bool flg = true;
   for(auto e : A.at(i)){
    if(H.at(i) <= H.at(e)){
     flg = false; 
    }
   }
   if(flg) ans++;
  }
  cout << ans << endl;
  return 0;
}