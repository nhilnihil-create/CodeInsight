#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int determine(vi &vec, string s, int i, int k){
  if (s.at(i) == s.at(i-k) && vec.at(i - k) == 0){
    vec.at(i) = 1;
    return true;
  }
  else {
    return false;
  }
}

int main(){
  int n, k, r, s, p;
  cin >> n >> k >> r >> s >> p;
  string S;
  cin >> S;
  vi vec((int)S.size());
  int ans = 0;
  rep(i,(int)S.size()){
    //cout << ans << endl;
    if (i<k){
      ans += S.at(i)=='s'? r : (S.at(i)=='p'? s : p);
      continue;
    }
    if (determine(vec, S, i, k)){
      continue;
    }
    ans += S.at(i)=='s'? r : (S.at(i)=='p'? s : p);
  }
  cout << ans << endl;
  return 0;
}
