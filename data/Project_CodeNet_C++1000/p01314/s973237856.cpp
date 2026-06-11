#include <iostream>

using namespace std;

main(){
  int n;
  while(cin >> n && n){
    int ans = 0;
    for(int i=2;i<=1000;i++){
      int tmp = (i*(i-1))/2;
      for(int j=1;j<=1000;j++){
        int tmp2 = j*i + tmp;
        if(tmp2 > n) break;
        if(tmp2 == n) ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}