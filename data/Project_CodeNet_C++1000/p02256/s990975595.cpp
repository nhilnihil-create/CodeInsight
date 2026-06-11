#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdio>
using namespace std;


int main(void){
  int a, b;
  cin >> a >> b;
  if(b > a){
    swap(a, b);
  }
  while(a && b){
    int t = a;
    a = b;
    b = t % b;
  }
  cout << a << endl;
  return 0;
}