#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main() {
  int n;
  cin >> n;
  int A[20];
  int x[20][20];
  int y[20][20];
  rep(i,n){
    int a;
    cin >> a;
    A[i] = a;
    rep(j,a){
      int p, q;
      cin >> p >> q;
      x[j][i] = p;
      y[j][i] = q;
    }
  }
  int ans = 0;
  
  for(int bit = 0; bit < (1<<n); bit++){
    bool have = true;
    bitset<15> s(bit);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (s.test(i)) {
        sum++;
        for(int j = 0; j < A[i]; j++){
          if(y[j][i] == 1){
            if(s.test(x[j][i]-1)){
            }
            else{
              have = false;
            }
          }
          if(y[j][i] == 0){
            if(s.test(x[j][i]-1)){
              have = false;
            }
          }
        }   
      }
    }
    
    if(have){
      
      ans = max(ans,sum);
    }
  }
   
  cout << ans;
    
  return 0;
}