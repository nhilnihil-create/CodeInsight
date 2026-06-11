
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<numeric>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<typename A, typename B> bool chmin(A &a, const B &b){ return b < a && (a = b, true); }
template<typename A, typename B> bool chmax(A &a, const B &b){ return a < b && (a = b, true); }

int main() {
  int n,cnt = 0,c = 0,cc = 0;
  cin >> n;
  vector<int> p(n),p1(n),c2(60);
  for (int i = 0; i < n; i++){
    cin >> p[i];
    p1[i] = p[i];
  }
  sort(p1.begin(),p1.end());
  for (int i = 0; i < n; i++){
    if (p1[i] != p[i]){
      cnt++;
      c2[i]++;
      if (c != 0){
        c = i;
      }
      else{
        cc = i;
      }
    }
  }
  if (cnt > 2 || cnt == 1){
    cout << "NO\n";
    return 0;
  }
  else{
    cout << "YES\n";
  }
  
  return 0;
}