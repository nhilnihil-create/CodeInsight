#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

double dist(int x[],int y[],int n,int p){
  long long sum = 0;
  for(int i=0;i<n;i++){
    sum += pow(abs(x[i] - y[i]),p);
  }
  return pow(sum,1.0/(double)p);
}

int main(){
  int n;
  cin>>n;
  int x[n],y[n];
  for(int i=0;i<n;i++){
    cin>>x[i];
  }
  for(int i=0;i<n;i++){
    cin>>y[i];
  }

  printf("%.10lf\n",dist(x,y,n,1));
  printf("%.10lf\n",dist(x,y,n,2));
  printf("%.10lf\n",dist(x,y,n,3));
  double max = -1.0;
  for(int i=0;i<n;i++){
    int tmp = abs(x[i] - y[i]);
    if(max<tmp) max=tmp;
  }
  printf("%.10lf\n",max);

  return 0;
}