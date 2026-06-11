#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define chmax(x,y) x = max(x,y)

int dist(int D, vector<int> a, vector<int> b){
  int res = 0;
  rep(i,D){
    res += (a[i] - b[i]) * (a[i] - b[i]);
  }
  return res;
}

bool issqrt(int a){
  return int(pow(int(sqrt(a)),2)) == a;
}

int main() {
  int N,D;
  cin >> N >> D;
  vector<vector<int>> X(N);
  
  rep(i,N){
    rep(j,D){
      int tmp;
      cin >> tmp;
      X[i].push_back(tmp);
    }
  }

  int ans=0;
  for(int i = 0; i < N; i++){
    for(int j = i+1; j<N; j++){
      if(issqrt(dist(D, X[i], X[j]))){
        ans++;
      }
    }
  }
  cout << ans << endl;
}