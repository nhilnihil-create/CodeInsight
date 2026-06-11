#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

ll combination(int n,int k){//組み合わせ
  ll ans = 1;
  if (k == 1){
    return n / k;
  }
  ans = n * combination(n-1, k-1) / k;
  return ans;
}

int main(){
  int n;
  cin >> n;
  vector<string> vec(n+1);
  vec.at(n) = "zzzzzzzzzzz";
  rep(i,n){
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vec.at(i) = s;
  }
  sort(vec.begin(), vec.end());
  /*rep(i,n){
    cout << vec.at(i) << endl;
  }*/
  int cnt = 1;
  ll ans = 0;
  rep(i,n){
    if (vec.at(i) == vec.at(i+1)) cnt++;
    else if (cnt == 1) continue;
    else {
      ans += combination(cnt, 2);
      cnt = 1;
    }
  }
  cout << ans << endl;
  return 0;
}
