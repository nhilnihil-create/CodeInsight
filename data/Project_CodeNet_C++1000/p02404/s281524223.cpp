#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

int main(){
  int x, y;
  while(1) {
    cin >> x >> y;
    if ((x == 0) && (y == 0)) {
      break;
    }
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < y; j++) {
        if ((i == 0) || (j == 0) || (i == x - 1) || (j == y - 1)) {
          cout << '#';
        } else {
          cout << '.';
        }
      }
      cout << endl;
    }
    cout <<endl;
  }
}