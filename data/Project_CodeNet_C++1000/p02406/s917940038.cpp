#include <iostream>
using namespace std;

void include3(int x, int i){
  if(x % 10 == 3) {
    cout  << " " << i;
  }else{
    x /= 10;
    if(x) include3(x, i);
  }
}

void call(int n){
  int i, x;

  for(i = 1; i < n+1; ++i){
    x = i;
    if(x % 3 == 0) {
      cout << " " << i;
    }else{
      include3(x, i);
    }
  }
  
}

int main(){
  int n;
  cin >> n;

  call(n);
  cout << endl;
}