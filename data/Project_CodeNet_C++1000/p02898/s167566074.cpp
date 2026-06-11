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
  int N,K,num=0;
  cin>>N>>K;

  vector<int> vec(N);
  for (int i=0;i<N;i++){
    cin>>vec.at(i);
  }

  for (int j=0;j<N;j++){
    if (vec.at(j)>=K)
    num+=1;
  }

  cout<<num<<endl;
  return 0;
  





  
}
