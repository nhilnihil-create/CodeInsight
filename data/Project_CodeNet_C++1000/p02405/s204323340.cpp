#include <iostream>
using namespace std;

int main()
{
  int H, W;

  while(true){
      cin >> H >> W;
      if(H==0&W==0) break;
      else {
        for(int i=0; i<H; i++){
          for(int j=0; j<W; j++){
            if(i%2==0){ // 偶数行は#から始まる
              if(j%2==0)cout << "#";
              else cout << ".";
            } else {
              if(j%2==0) cout << ".";
              else cout << "#";
            }
          }
          cout << endl;
        }
        cout << endl;
      }
  }
}

