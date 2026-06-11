#include <iostream>
using namespace std;

int N;
int R;
int I;

int main(){
  cin >> N >> R;
  if(N >= 10){
    I = R;
  }
  else{
    I = R + (100 * (10 - N));
  }
  cout << I;
}