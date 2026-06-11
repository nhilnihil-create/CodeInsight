#include<bits/stdc++.h>
using namespace std;
double D(double a,double b,double c,double d){
   double res=sqrt((a-b)*(a-b)+(c-d)*(c-d));
   return res;
}
int main(void){
   int N;
   cin>>N;
   vector<double> x(N),y(N);
   for(int i=0;i<N;i++){
      cin>>x[i]>>y[i];
   }
   double ans=0.0;
   vector<int> town(N);
   for(int i=0;i<N;i++){
      town[i]=i;
   }
   int rec=0;
   do{
      rec++;
      double dist=0.0;
      for(int i=0;i<N-1;i++){
         dist+=D(x[town[i]],x[town[i+1]],y[town[i]],y[town[i+1]]);
      }
      ans+=dist;
   }while(next_permutation(town.begin(),town.end()));
   cout<<fixed;
   cout<<setprecision(7)<<ans/(double)rec<<endl;
   return 0;
}
