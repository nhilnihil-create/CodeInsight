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
  int H,W,N;
  cin >> H >> W >> N;
  if(H >= W){
    rep(i,W+1){
      if(i * H >=N){
        cout << i << endl;
        return 0;
      }
    }

  }else{
    rep(i,H+1){
      if (i * W >= N) {
        cout << i << endl;
        return 0;
      }
    }
  }
  return 0;
}
