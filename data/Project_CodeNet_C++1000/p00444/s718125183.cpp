#include <iostream>

using namespace std;

main(){
  int x;
  while(1){
    cin >> x;
    if(x==0) break;

    x=1000-x;
    int ans=0;
    if(x>=500){
      ans++;
      x-=500;
    }
    while(x>=100){
      ans++;
      x-=100;
    }
    if(x>=50){
      ans++;
      x-=50;
    }
    while(x>=10){
      ans++;
      x-=10;
    }
    if(x>=5){
      ans++;
      x-=5;
    }
    ans+=x;
    cout << ans << endl;
  }
  return 0;
}