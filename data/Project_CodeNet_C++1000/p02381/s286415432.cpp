#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
 int n;
 double s[1000],sum,dist,m;

 while(1){
  cin >> n;
  sum = 0.0;
  dist = 0.0;
  if(n == 0) break;

  for(int i = 0; i < n; i++){
   cin >> s[i];

   sum += s[i];
  }
  m = sum / n; 
 
  for(int i = 0; i < n; i++){
   dist += pow(s[i] - m, 2);
  }

  printf("%lf\n", sqrt(dist / n));
 }

 return 0;
}