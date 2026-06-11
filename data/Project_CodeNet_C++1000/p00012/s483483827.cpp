#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#include<utility>
#include<string>

using namespace std;

double eps=1e-6;

main(){
  int i,j,l;
  double x[4],y[4],a,b,c,s,tol,ans,temp[3];
  while(cin >> x[0] >>y[0]){
    for(i=1;i<=3;i++){
      cin >> x[i] >> y[i];
    }

    a=pow(x[0]-x[1],2)+pow(y[0]-y[1],2);
    a=sqrt(a);
    b=pow(x[1]-x[2],2)+pow(y[1]-y[2],2);
    b=sqrt(b);
    c=pow(x[2]-x[0],2)+pow(y[2]-y[0],2);
    c=sqrt(c);
    s=(a+b+c)/2;
    tol=sqrt(s*(s-a)*(s-b)*(s-c));

    for(i=0;i<3;i++){

      if(i==1){
      a=pow(x[3]-x[2],2)+pow(y[3]-y[2],2);
      a=sqrt(a);
      }
      else{
      a=pow(x[3]-x[0],2)+pow(y[3]-y[0],2);
      a=sqrt(a);
      }

      b=pow(x[i]-x[i+1],2)+pow(y[i]-y[i+1],2);
      b=sqrt(b);

      if(i==2){
      c=pow(x[2]-x[0],2)+pow(y[2]-y[0],2);
      c=sqrt(c);
      }
      else{
      c=pow(x[3]-x[1],2)+pow(y[3]-y[1],2);
      c=sqrt(c);
      }

      s=(a+b+c)/2;
      temp[i]=sqrt(s*(s-a)*(s-b)*(s-c));
    }
    ans=temp[0]+temp[1]+temp[2];
    //   printf("%f %f\n",tol,ans);

    if(fabs(tol-ans)<eps){
      puts("YES");
    }
    else{
      puts("NO");
    }

  }
}