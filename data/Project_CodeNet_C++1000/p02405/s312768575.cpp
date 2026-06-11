#include<iostream>
using namespace std;

int main(){
  int H,W;
  while(1){
    cin >> H >> W;
    if(H==0 && W==0) break;

    bool flag = true;
    for(int i=0;i<H;i++){
      if(i%2==0) flag = true;
      else flag = false;
      for(int j=0;j<W;j++){
        if(flag){
          cout << "#";
          flag = false;
        }else{
          cout << ".";
          flag = true;
        }
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}
      