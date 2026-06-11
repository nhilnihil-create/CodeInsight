#include<iostream>
#include <iomanip>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>

using namespace std;
int main(){

  string w,t;

  cin >> w;

  int sum;

  for(int i=0;i<w.size();i++){
    if(65 <= (int)w[i] && (int)w[i] <= 90){
      w[i] = (char)((int)w[i] + 32);
    }
  }

  while(true){
    cin >> t ;
    if(t.compare("END_OF_TEXT") == 0) break;
    for(int i=0;i<t.size();i++){
      if(65 <= (int)t[i] && (int)t[i] <= 90){
        t[i] = (char)((int)t[i] + 32);
      }
    }
    if(t.compare(w) == 0) {
      sum++;
    }
  }

  cout << sum <<endl;

}
