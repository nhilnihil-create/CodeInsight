#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N, M, X;
  cin >> N >> M >> X;
  vector<int> C(N);
  vector<vector<int>> A(N, vector<int>(M, 0));
  
  int ans = 1200001;
  rep(i, N){
    cin >> C.at(i);
    rep(j, M) cin >> A.at(i).at(j);
  }
  
  
  for (int tmp = 0; tmp < (1 <<N); tmp++) {
    bitset<12> b(tmp);
    
    
    int sum = 0;
    bool flg = true;
    vector<int> s = vector<int>(M, 0);//skill
    
    rep(i, N){
      
      if(b.test(i)){
        sum += C.at(i);
        rep(j, M){
          
         s.at(j) += A.at(i).at(j); 
        }
      }
    }
    rep(i, M){
      if(s.at(i) < X){
      	flg = false;
        break;
      }
    }
    if(flg){
     ans = min(ans, sum);
    }
    
  }
  if(ans == 1200001) cout << -1 << endl;
  else cout << ans << endl;
 
  return 0;
}