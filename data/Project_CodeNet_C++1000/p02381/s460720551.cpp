#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstring>
#include <map>
#include <cctype>
#include <string>
#include <cstdlib>
#include <math.h>
using namespace std;

#define REP(i,n)  for(int i=0; i<n; i++)

int main()
{
  cout << setprecision(6);
  cout << setiosflags(ios::scientific);
  cout.flags(ios::fixed);

  while(true){
  int n;
  cin >> n;
  if(n==0) break;

  int score[n];
  REP(i,n){
    cin >> score[i];
  }

  int sum=0;
  REP(i,n){
    sum += score[i];
  }
  double ave = (double)sum / n;

  double t=0.0;
  REP(i,n){
    t += pow(ave - (double)score[i], 2 );
  }
  cout << sqrt(t/n) << endl;

    }
}