#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <string>
#include<iomanip>
#include<limits>
using namespace std;
int main(void){
   int N;
   cin>>N;
   int P[N];
   double a=1;
   for(int i=0;i<N;i++){
       cin>>P[i];
       a*=P[i];
   }
   bool Q[N];
   for(int i=0;i<N;i++){
       Q[i]=true;
   }
   double sum=0;
   double c=1;
   for(int i=0;i<N;i++){
       Q[i]=false;
       for(int j=0;j<N;j++){
           if(Q[j]){
               c*=P[j];
           }
       }
       sum+=c;
       c=1;
       Q[i]=true;
   }
   cout<<setprecision(12)<<double(a/sum)<<endl;
}
