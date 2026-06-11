#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>

#define sqr(x) ((x)*(x))
#define sqr3(x) ((x)*(x)*(x))
using namespace std;
int main(){
  int n;
  cin>>n;
  double maxx=-1;
  double x[n],y[n],dis[n],ans1=0,ans2=0,ans3=0,ansinf=0;
  for(int i=0;i<n;i++)
    cin>>x[i];
  for(int i=0;i<n;i++){
    cin>>y[i];
    if(x[i]>y[i]){
      dis[i]=(x[i]-y[i]);
    }else{
      dis[i]=(y[i]-x[i]);  
    }
    maxx=max(dis[i],maxx);
    ans1+=dis[i];
    ans2+=sqr(dis[i]);
    ans3+=sqr3(dis[i]);
  }
  printf("%.6lf\n",ans1);
  printf("%.6lf\n",sqrt(ans2));
  printf("%.6lf\n",pow(ans3,1.0/3.0));
  printf("%.6lf\n",maxx);
  return 0;
}