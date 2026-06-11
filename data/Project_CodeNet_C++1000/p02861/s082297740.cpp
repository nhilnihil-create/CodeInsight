#include <bits/stdc++.h>
using namespace std;

double dist(double x1,double x2,double y1,double y2){
  double dx=x1-x2,dy=y1-y2;
  return sqrt(dx*dx+dy*dy);
}

int main() {
  double n;	cin >> n;
  vector<double>	x(n),y(n);
  for(int i=0;i<n;i++)	cin >> x[i] >> y[i];
  
  vector<int>	junretu(n);
  for(int i=0;i<n;i++)	junretu[i]=i;
  
  double c=0,sum=0;
  do{
    for(int i=0;i<n-1;i++){
      int x1=x[junretu[i]];
      int x2=x[junretu[i+1]];
      int y1=y[junretu[i]];
      int y2=y[junretu[i+1]];
      sum+=dist(x1,x2,y1,y2);
    }
    c++;
  }while(next_permutation(junretu.begin(),junretu.end()));
  printf("%.10f",sum/c);
}