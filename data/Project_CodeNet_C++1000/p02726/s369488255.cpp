#include<bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
#define int long long

signed main(){
  int N, X, Y;
  cin >> N >> X >> Y;X--;Y--;
  map<int, int> d;
  rep(i,N){
      rep(j,N){
          if(i==j)continue;
        d[min({abs(j - i),abs(X - i) + abs(j - Y) + 1, abs(Y - i) + abs(j - X) + 1})]++;
      }
    }
  for(int i = 1;i < N;i++){
      cout << d[i]/2 << endl;
  }
}

