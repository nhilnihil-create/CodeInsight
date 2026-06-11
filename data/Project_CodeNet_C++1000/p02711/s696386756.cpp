#include<iostream>
using namespace std;
int main(){
  int a; cin >> a;
  while(a > 0){
    if((a % 10) == 7){
      printf("Yes");
      return 0;
    }
    else{
      a /=10;
    }
  }
  cout << "No" << endl;
}