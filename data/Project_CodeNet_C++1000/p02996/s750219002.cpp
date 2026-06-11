#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  int n;
  cin >> n;

  vector<pair<int, int>> vec(n);
  rep(i,n){
    int a, b;
    cin >> a >> b;
    vec.push_back(make_pair(b, a));
  }
  
  sort(vec.begin(), vec.end());
  ll cnt = 0;
  bool flag = true;
  for (auto p: vec){
    int a, b;
    tie(b, a) = p;
    cnt += a;
    if (cnt > b){
      flag = false;
    }
  }
  cout << (flag? "Yes" : "No") << endl;
  return 0;
}
