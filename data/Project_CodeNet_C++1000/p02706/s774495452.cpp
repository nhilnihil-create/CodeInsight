#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M;
  int ans=0;
  for(int i=0;i<M;i++){
    int x;
    cin >> x;
    ans+=x;
    if(ans>N){
      cout << -1 << endl;
      return 0;
    }
  }
  cout << N-ans << endl;
}