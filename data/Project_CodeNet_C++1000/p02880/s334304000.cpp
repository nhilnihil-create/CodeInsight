/*
 * a.cc:
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>
#include<iomanip>

using namespace std;

/* constant */

/* typedef */

/* global variables */

/* subroutines */

/* main */

int main(){
  int N,M=0;
  cin>>N;

  

  

  for (int i=1;i<=9;i++){
    for (int j=1;j<=9;j++){

      if (i*j==N){
        M=1;
        break;
        
      }
    }
  }
  if (M==1){
    cout<<"Yes"<<endl;
    
  }
  else {
    cout<<"No"<<endl;
    
  }
  return 0;
  
}











