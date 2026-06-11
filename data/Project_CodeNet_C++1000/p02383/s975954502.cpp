#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Dice{
private:
  vector<int> data;

public: 
  Dice(): data(6,0){}
  Dice(vector<int> data): data(data){}

  void print_top(){
    cout << data[0] << endl;
  }  

  void print_all(){
    for(int d: data){
      cout << d << " ";
    }
    cout << endl;
  }

  void roll(char c){
    if(c == 'S'){
      swap(data[0], data[1]);
      swap(data[4], data[5]);
      swap(data[0], data[5]);
    }else if(c == 'N'){
      swap(data[0], data[1]);
      swap(data[4], data[5]);
      swap(data[1], data[4]);
    }else if(c == 'E'){
      swap(data[0], data[2]);
      swap(data[3], data[5]);
      swap(data[0], data[5]);
    }else if(c == 'W'){
      swap(data[0], data[2]);
      swap(data[3], data[5]);
      swap(data[2], data[3]);
    }
  }
};


int main(){
  vector<int> data(6);
  for(int i=0; i<6; i++){
    cin >> data[i];
  }
  Dice dice(data);

  string ops; cin >> ops;
  for(char op: ops){
    dice.roll(op);
  }

  dice.print_top();

  return 0;
}