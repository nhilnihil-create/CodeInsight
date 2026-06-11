#include<iostream>
#include<string>
using namespace std;
 
int main(){
  string n;
  cin >> n;
  for(int i = 0;i < 3;i++){
    if(n.at(i) == '7'){
      cout << "Yes";
      break;
    }
    if(i == 2){
      if(n.at(2) != '7'){
      cout << "No";
    }
    }
  }
}