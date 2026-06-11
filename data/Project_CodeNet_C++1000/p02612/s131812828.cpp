#include<iostream>
using namespace std;

int main(){
  int n;
  cin >> n;

  if(n<=1000){
    cout << 1000-n << endl;
  }else if(n <= 2000){
    cout << 2000-n << endl;
  }else if(n<=3000){
    cout << 3000-n << endl;
  }else if(n<=4000){
    cout << 4000-n << endl;
  }else if(n<=5000){
    cout << 5000-n << endl;
  }else if(n<=6000){
    cout << 6000-n << endl;
  }else if(n<=7000){
    cout << 7000-n << endl;
  }else if(n<=8000){
    cout << 8000-n << endl;
  }else if(n<=9000){
    cout << 9000-n << endl;
  }else{
    cout << 10000-n << endl;
  }

  return 0;
}