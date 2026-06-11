#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
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
typedef pair<int, int> PII;
static const double EPS = 1e-5;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)

int main(void){
  int n,p;
  while(cin>>n>>p){
    if(n==0) break;
    vector<int> a(n);
    int i=0;
    while(1){
      if(p){
        p--;
        a[i]++;
        if(p==0&&count(a.begin(),a.end(),0)==n-1){
          cout<<i<<endl;
          break;
        }
      }else{
        p = a[i];
        a[i] = 0;
      }
      i=(i+1)%n;
    }
  }
  return 0;
}