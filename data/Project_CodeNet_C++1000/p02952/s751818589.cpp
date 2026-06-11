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
  int N,num=0;
  cin>>N;

  for (int i=1;i<=N;i++){
    if (to_string(i).length()%2==1) {
      num++;
      
    }
  }
  cout<<num<<endl;
  return 0;
  
}