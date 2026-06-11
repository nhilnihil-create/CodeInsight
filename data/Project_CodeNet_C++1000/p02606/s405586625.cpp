#include <bits/stdc++.h>
using namespace std;

int main() {
  int L,R,D,ans=0;
  cin >> L >> R >> D;
  for(int i=L; i<=R; i++){
    if(i%D == 0){
      ans++;
    }
  }
  cout << ans << endl;
}
