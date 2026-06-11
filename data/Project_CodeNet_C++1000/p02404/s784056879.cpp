#include<iostream>
using namespace std;

int main(){

  for (int x = 0;true;x++){
    int h,w;
    cin >> h >> w;

    if (h == 0 && w ==0) break;

    for (int i = 1; i <=h; i++){
      if (i == 1 || i == h){
        for (int j = 1; j <= w; j++){
          cout << "#";
        }
        cout << endl;
      }
      else{
        for (int j = 1; j <= w; j++){
          if (j == 1 || j == w){
            cout << "#";
          }
          else{
            cout << ".";
          }
        }
        cout << endl;
      }
    }
    cout << endl;
  }

  return 0;

}