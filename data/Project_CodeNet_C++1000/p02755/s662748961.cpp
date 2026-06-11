#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int A, B;
  cin >> A >> B;
  
  for(int i=1; i<=1250; i++){
    if((int)(i*0.08) == A && (int)(i*0.1) == B){
     cout << i << endl; 
     return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}