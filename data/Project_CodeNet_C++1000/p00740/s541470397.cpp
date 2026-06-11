#include <iostream>

using namespace std;

main(){
  int n, p, data[50], wan;
  while(cin >> n >> p && (n|p)){
    for(int i=0;i<50;i++) data[i] = 0;
    wan = p;
    int pos = 0;
    for(;;){
      if(wan){
        if(++data[pos] == p) break;
        wan--;
      }else{
        wan += data[pos];
        data[pos] = 0;
      }
      pos = (pos + 1) % n;
    }
    cout << pos << endl;
  }
}