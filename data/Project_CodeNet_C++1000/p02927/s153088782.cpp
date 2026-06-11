#include <bits/stdc++.h>
#define For(i,n) for(int i=0; i<n; i++)
using namespace std;

int main(){

  int M,D;
  int ans=0;
  cin >> M >> D;

  for(int i=22; i<=D; i++){
    int ten, one;
    ten = (i/10)%10;
    one = i%10;
    if(one<2) continue;
    else if(ten*one<=M) ans++;
  }

  cout << ans << endl;

  return 0;
}