#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
//using P = pair<int,int>;

int main(){
  int a,b;
  cin >> a >> b;
  string A = to_string(a);
  string B = to_string(b);
  string ansA,ansB;
  rep(i,b){
    ansA += A;
  }
  rep(i,a){
    ansB += B;
  }
  string ans = min(ansA,ansB);
  cout << ans << endl;
}
