#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <fstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> P;
static const double EPS = 1e-5;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)

int main(void){
  int N;
  while(cin>>N){
    int p1=0,p2=0;
    if(N==0) break;
    REP(i,N){
      int n1,n2;
      cin>>n1>>n2;
      if(n1>n2){
        p1+=n1+n2;
      }else if(n1<n2){
        p2+=n1+n2;
      }else{
        p1+=n1;
        p2+=n2;
      }
    }
    cout<<p1<<" "<<p2<<endl;
  }
  return 0;
}