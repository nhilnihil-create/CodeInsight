#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
int main(void){
  string str;
  cin >> str;
  int N[4];
  transform(begin(str), end(str), N, [](char c) {return c - '0';} );
  int i = 0;
  int flg = 0;
  while(i < 3){
	if (N[i] == N[i+1]){ flg = 1; }
    i++;
  }
  if (flg == 1) { cout << "Bad" << endl; }
  else{ cout << "Good" << endl; }
  return 0;  
}

  