#include<iostream>
#include<cmath>
#include<tuple>
#include<algorithm> // sort,reverse
using namespace std;
#define df 0
long int norm(long int x,long int y){
  return x*x+y*y;
}

int main(){
  if(df) printf("*debug mode*\n");
  int n; cin >> n;
  tuple<double,int,int> engs[2*n];
  for(int i=0;i<n;i++){
    int x,y;
    cin >> x >> y;
    get<0>(engs[i])=atan2(x,y);
    get<1>(engs[i])=x;
    get<2>(engs[i])=y;
  }
  sort(engs,engs+n);
  for(int i=0;i<n;i++){
    engs[i+n]=engs[i];
  }
  if(df){
    for(int i=0;i<2*n;i++){
      printf("%lf,%d,%d\n",get<0>(engs[i]),get<1>(engs[i]),get<2>(engs[i]));
    }
  }
  long int max_d=0;
  for(int i=0;i<n;i++){
    long int x=0,y=0;
    for(int j=0;j<n;j++){
      x+=get<1>(engs[i+j]);
      y+=get<2>(engs[i+j]);
      long int temp=norm(x,y);
      if(max_d<temp){
	max_d=temp;
	if(df)printf("%d %d %ld\n",x,y,max_d);
      }
    }
  }
  printf("%.15lf",sqrt(max_d));
}

/// confirm df==0 ///