#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  int n, m, x;
  cin >> n >> m >> x;
  m++;
  vvi vec(n, vi(m));
  rep(i,n){
    rep(j,m){
      cin >> vec.at(i).at(j);
      //printf("%d ", vec.at(i).at(j));
  }
  //cout << endl;
}

  int ans = 0;
  rep(i,n){
    ans += vec.at(i).at(0);
    //printf("ans:%d\n", ans);
  }

  bool never = false;
  rep(tmp,(1<<n)){
    int index = 0;
    bitset<12> s(tmp);
    vi X(m,x);
    vi Y(m);
    rep(i,n){
      if (s.test(i)){
        index +=vec.at(i).at(0);
        REP(j,1,m){
          Y.at(j) += vec.at(i).at(j);
        }
      }
    }

    bool flag = true;
    REP(i,1,m){
      if (Y.at(i) < X.at(i)) flag = false;
    }
    //printf("index:%d, ans:%d\n", index, ans);
    if (flag){
      ans = min(ans, index);
      never = true;
    }
  }
  //cout << endl;
  if (never) cout << ans << endl;
  else cout << -1 << endl;
  return 0;
}
