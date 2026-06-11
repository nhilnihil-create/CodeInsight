#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,X,Y;
  cin >> N >> X >> Y;
  vector<int>ans(N-1);
  for(int i=1;i<N+1;i++){
    for(int j=i+1;j<N+1;j++){
      int x;
      x=min(j-i,abs(Y-j)+abs(X-i)+1);
      ans.at(x-1)++;
    }
  }
  for(int i=0;i<N-1;i++){
    cout << ans.at(i) << endl;
  }
}