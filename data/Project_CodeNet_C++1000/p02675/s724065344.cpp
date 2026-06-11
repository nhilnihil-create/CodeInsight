#include<string>
#include<iostream>
using namespace std;

int main(){
  string s;
  cin >> s;
  if(s.at(s.length()-1) == '3'){
    cout << "bon" << endl;
  }else if(s.at(s.length()-1) == '0' || s.at(s.length()-1) == '1' || s.at(s.length()-1) == '6'
           || s.at(s.length()-1) == '8'){
    cout << "pon" << endl;
  }else{
    cout << "hon" << endl;
  }
}
