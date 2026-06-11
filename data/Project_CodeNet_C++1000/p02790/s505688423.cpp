#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int a, b;
  cin >> a >> b;

  if (a <= b){
    rep(i,b) cout << a;
    cout << endl;
  }else{
    rep(i,a) cout << b;
    cout << endl;
  }
}
