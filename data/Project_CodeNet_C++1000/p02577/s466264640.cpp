#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

int main(){
  string n;
  cin >> n;
  int count = 0;
  for(int i=0;i<n.size();i++){
    count += (int)n.at(i)-48;
  }
  if(count%9 == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
}