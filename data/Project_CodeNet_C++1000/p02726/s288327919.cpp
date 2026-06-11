#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N,X,Y;cin >> N >> X >> Y;
  vector<int> L(N,0);
  for(int i=1;i<=N;i++){
    for(int j=i+1;j<=N;j++){
      int l = j-i;
      l = min(l,abs(X-i)+abs(Y-j)+1);
      l = min(l,abs(X-j)+abs(Y-i)+1);
      L[l] ++;
    }
  }
  for(int i=1;i<N;i++){
    cout << L[i] << endl;
  }
}