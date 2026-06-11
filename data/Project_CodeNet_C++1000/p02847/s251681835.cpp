#include <iostream>
#include <map>
using namespace std;

int main(){
  map<string,int> m;
  m["MON"]=1;
  m["TUE"]=2;
  m["WED"]=3;
  m["THU"]=4;
  m["FRI"]=5;
  m["SAT"]=6;
  m["SUN"]=0;
  string S;
  cin >> S;
  cout << 7-m[S];
}