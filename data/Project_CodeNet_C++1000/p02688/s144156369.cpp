#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  cin >> N >> K;
  vector<bool>data(N+1,false);
  for(int i=0;i<K;i++){
    int a;
    cin >> a;
    for(int j=0;j<a;j++){
      int b;
      cin >> b;
      data.at(b)=true;
    }
  }
  int ans=0;
  for(int i=1;i<N+1;i++){
    if(!data.at(i)) ans++;
  }
  cout << ans << endl;
}
