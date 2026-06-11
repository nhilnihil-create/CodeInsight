#include<iostream>
using namespace std;
int main(){
  int hp, a;
  cin >> hp >> a;
  for(int i = 0; i < 100000; i++){
    if(hp <= 0){
      cout << i;
      return 0;
    }
    hp = hp - a;
  }
}