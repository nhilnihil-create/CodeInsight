#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int X;
  cin >> X;

  int happy = 0;

  while(X >= 500){
    X -= 500;
    happy += 1000;
  }

  while(X >= 5){
    X -= 5;
    happy += 5;
  }

  cout << happy << endl;
}
