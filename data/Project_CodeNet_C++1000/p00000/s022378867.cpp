#include<iostream>

using namespace std;

int main(){
    int y,i;
    for(y = 1;y < 10;y++){
          for(i = 1;i < 10;i++){
          cout << y << "x" << i << "=" << y*i << endl;
          }
    }
}