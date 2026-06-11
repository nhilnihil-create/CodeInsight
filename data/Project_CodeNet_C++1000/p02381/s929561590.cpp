#include<iostream>
#include<valarray>
#include<cmath>
using namespace std;
int n;
valarray<double> data;
int inp(){
  cin>>n;
  if(!n)return 0;
  data=valarray<double>(n);
  for(int i=0;i<n;i++)
    cin>>data[i];
  return n;
}
double avg;
double app(double x){return (x-avg)*(x-avg);}
void proc(){
  avg=data.sum()/n;
  double result=sqrt(data.apply(app).sum()/n);
  printf("%lf\n",result);
}
int main(){
  while(inp())proc();
  return 0;
}