#include <bits/stdc++.h>
#define rep(i,n) for(int i=1; i<(n); ++i)
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  rep(i,10100){
    int x=i*8/100, y=i*10/100;
    if(a==x && b==y){
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
