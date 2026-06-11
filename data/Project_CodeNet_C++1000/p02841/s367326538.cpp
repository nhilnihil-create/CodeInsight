#include <bits/stdc++.h>
#define rep2(i,m,n) for (int i = (int)(m); i < (int)(n); i++)
#define rep(i,n) rep2(i,0,n)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
using ll = long long;
template <typename T>
T sq(T x){
  return x * x;
}

signed main (){
  int M[2] , D[2];
  rep(i,2){
  cin >> M[i] >> D[i];
  }
  if (M[0] != M[1]){
    cout << '1' << endl;
  }else {

cout << '0' << endl;
  }
    return 0;
}
