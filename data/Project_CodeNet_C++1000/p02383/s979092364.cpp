#include <iostream>
#include <string>
using namespace std;

class Dice{
private:
  int d[6];

public:
  void input();
  void rotation(char c);
  void output();
};

int main(){
  Dice dice;
  string s;

  dice.input();
  cin >> s;
  for(int i = 0; i < s.size(); i++){
    dice.rotation(s[i]);
  }
  dice.output();
}

void Dice::input(){
  for(int i = 0; i < 6; i++){
    cin >> d[i];
  }
}

void Dice::rotation(char c){
  int tmp;
  if(c == 'N'){
    tmp = d[0]; d[0] = d[1]; d[1] = d[5]; d[5] = d[4]; d[4] = tmp;
  }else if(c == 'S'){
    tmp = d[0]; d[0] = d[4]; d[4] = d[5]; d[5] = d[1]; d[1] = tmp;
  }else if(c == 'W'){
    tmp = d[0]; d[0] = d[2]; d[2] = d[5]; d[5] = d[3]; d[3] = tmp;
  }else if(c == 'E'){
    tmp = d[0]; d[0] = d[3]; d[3] = d[5]; d[5] = d[2]; d[2] = tmp;
  }
}

void Dice::output(){
  cout << d[0] << endl;
}