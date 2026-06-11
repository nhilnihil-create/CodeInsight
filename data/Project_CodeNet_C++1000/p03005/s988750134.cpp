#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,K; cin >> N >> K;
  if(N>=K && K>1) cout << N-K << endl;
  else cout << 0 << endl;
}