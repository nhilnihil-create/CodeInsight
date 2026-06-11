#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main () {
  int i, N, judge=0;
  
  cin >> N;
  
  rep(i,9){
    if(N%(i+1)==0 && N/(i+1) < 10) {
      judge=1;
      break;
    }
  }
  
  if(judge) cout << "Yes";
  else cout << "No";
}




