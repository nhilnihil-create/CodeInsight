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
  string S;
  cin>>S;

  int M;
  M=S.size();

  

  for (int i=0;i<M;i++){
    if (i==0 && S.at(i)=='L'){
      cout<<"No"<<endl;
      return 0;
      
    }

    
    if(i%2==0 && S.at(i)=='L'){
      cout<<"No"<<endl;
      return 0;
    }

    if(i%2==1 && S.at(i)=='R'){
      cout<<"No"<<endl;
      return 0;
    }





  }

  cout<<"Yes"<<endl;
  return 0;
  
}
