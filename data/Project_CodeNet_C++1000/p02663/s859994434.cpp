#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int h1,m1,h2,m2,k ;
  int time = 0;
  cin >> h1>>m1>>h2>>m2>>k;
  if(m1<=m2){
      time=(h2-h1)*60+(m2-m1)-k;
  }else{
      time=(h2-h1-1)*60+(m2+60-m1)-k;
  }
  if(time>=0){
  cout << time << endl;
  }else{
  cout << "0" << endl;
  }
} 