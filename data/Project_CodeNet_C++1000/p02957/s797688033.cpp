#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <iomanip>
#include <string.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()

typedef long long lint;

using namespace std;

int main(){
  int A,B;
  cin>>A>>B;
  if((A+B)%2){
    cout<<"IMPOSSIBLE"<<endl;
  }else{
    cout<<(A+B)/2<<endl;
  }
  return 0;
}
