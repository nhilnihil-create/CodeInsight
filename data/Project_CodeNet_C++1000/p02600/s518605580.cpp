#include <iostream>
using namespace std;

int main (){
  int a,b=8;
  cin >> a;
  if (a>=600) b=7;
  if (a>=800) b=6;
  if (a>=1000) b=5;
  if (a>=1200) b=4;
  if (a>=1400) b=3;
  if (a>=1600) b=2;
  if (a>=1800) b=1;
  cout << b;
}