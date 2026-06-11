#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
 
int main()
{
  cout << setprecision(6);
  cout << setiosflags(ios::scientific);
  cout.flags(ios::fixed);
 
  while(true){
    int h, w;
    cin >> h >> w;
 
    if(h==0&&w==0)
      break;
 
    for(int i=0; i<h; i++){
      for(int j=0; j<w; j++){
    if((i+j)%2==0)
      cout << "#";
    else
      cout << ".";
      }
      cout << endl;
    }
    cout << endl;
  }
}