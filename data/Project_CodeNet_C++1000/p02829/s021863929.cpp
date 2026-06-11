#include <bits/stdc++.h>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
  int A,B,ans=1;
  cin >> A >> B;
  for(int i=1;i<4;i++){
    if(i!=A && i!=B) ans=i;
  }
  cout << ans << endl;
  return 0;
}

