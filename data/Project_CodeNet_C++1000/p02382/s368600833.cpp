#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ABS1(x,y) (x)>(y)?(x)-(y):(y)-(x)
#define ABS2(x,y) ((x)-(y))*((x)-(y))
#define ABS3(x,y) (x)>(y)?((x)-(y))*((x)-(y))*((x)-(y)):((y)-(x))*((y)-(x))*((y)-(x))
#define MAX(x,y) (x)>(y)?(x):(y)

using namespace std;
array<long double,100> x;
array<long double,100> y;

int main(){ _;
  int n=0; cin>>n;
  REP(i,n) cin>>x[i];
  REP(i,n) cin>>y[i];

  long double one=0,two=0,three=0,inf=0;
  REP(i,n){
    one+=ABS1(x[i],y[i]);
    two+=ABS2(x[i],y[i]);
    three+=ABS3(x[i],y[i]);
    inf=max(inf,ABS1(x[i],y[i]));
  }
  printf("%.6Lf\n",one);
  printf("%.6Lf\n",pow(two,1./2));
  printf("%.6Lf\n",pow(three,1./3));
  printf("%.6Lf\n",inf);
}