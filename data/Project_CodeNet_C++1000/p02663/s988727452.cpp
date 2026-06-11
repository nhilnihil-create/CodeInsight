#include<iostream>
using namespace std;

int main(){
  int h1,m1,h2,m2,k;
  int abs_hour,abs_min;
  int active_time;
  cin >> h1 >> m1 >> h2 >> m2 >> k;
  //cout << h1 << m1 << h2 << m2 << k;
  
  abs_hour = h2 - h1;
  abs_min = m2 - m1;
  
  active_time = abs_hour * 60 + abs_min;
  cout << active_time - k;
  return 0;
}