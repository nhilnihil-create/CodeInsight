#include<iostream>
#include<algorithm>
#include<vector>
#include <iomanip>
#include <cmath>
#include <string.h>
#include <stdio.h>

using namespace std;

int main(){

  int N;
  string S;
  
  cin >> N >> S;
  
  int cnt =0;
  for(int i=0; i<N; i++){
    if(i<2)
      continue;
    if(S.at(i-2)== 'A' && S.at(i-1)== 'B' && S.at(i) == 'C')
       cnt++;
  }
  
  
  cout << cnt << endl;
  

  
  return 0;
  
}
