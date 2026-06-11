#include <bits/stdc++.h>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
  string ans="No";
  int H,N;
  cin >> H >> N;
  vector<int> A(N);
  rep(i,N) {
    cin >> A[i];
    H=H-A[i];
    if(H<=0) ans="Yes";
  }
  
  cout << ans << endl;
  return 0; 
}