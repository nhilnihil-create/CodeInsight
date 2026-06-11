#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;

int main(){
  int n, ok=0, no=0;
  cin >> n;
  int a[n];
  rep(i,n) cin >> a[i];
  rep(i,n){
    if(a[i]%2!=0){
      continue;
    }
    if(!(a[i]%3==0 || a[i]%5==0)){
      cout << "DENIED" << endl;
      return 0;
    }
  }
  cout << "APPROVED" << endl;
  return 0;
}
