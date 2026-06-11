#include<iostream>
using namespace std;

int main(){

  for (int i = 0;true;i++){
    int h,w;
    cin >> h >> w;

    if (h == 0 && w ==0) break;

    for (int j = 1; j <=h; j++){
      for (int k = 1; k <= w; k++){
        cout << "#";
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;

}