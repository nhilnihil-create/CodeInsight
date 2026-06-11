#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>

using namespace std;
typedef long long LL;
static const double EPS = 1e-9;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n) 
int SumOfIntegers(int n, int s){
  if(n<0||s<0) return 0;
  if(n==1) return ((s<10)?1:0);
  int a[10],count=0,sum;
  REP(i,10) a[i] = i;
  do{
    sum = 0;
    REP(i,n) sum+=a[i];
    if(sum == s) count++;
  }while(next_permutation(a, a+sizeof(a)/sizeof(a[0])));
  int d=1;
  for(int i=10-n;i>0;i--) d*=i;
  for(int i=2; i<=n; i++) d*=i;
  return (count/d);
}

int main(void){
  int n,s;
  while(cin>>n>>s,n){
    cout << SumOfIntegers(n,s) << endl;
  }
  return 0;
}