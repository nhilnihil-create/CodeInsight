#include<bits/stdc++.h>
using namespace std;
double D(double a,double b,double c,double d){
   double res=sqrt((a-b)*(a-b)+(c-d)*(c-d));
   return res;
}
int main(void){
   int N;
   cin>>N;
   vector<int> p(N),q(N);
   for(int i=0;i<N;i++){
      cin>>p[i];
   }
   for(int i=0;i<N;i++){
      cin>>q[i];
   }
   vector<int> num(N);
   for(int i=0;i<N;i++){
      num[i]=i+1;
   }
   int a,b;
   int temp1=0;
   int temp2=0;
   do{
      temp1++;
      temp2++;
      bool flag1=true;
      bool flag2=true;
      for(int i=0;i<N;i++){
         if(num[i]!=p[i]){
            flag1=false;
         }
         if(num[i]!=q[i]){
            flag2=false;
         }
      }
      if(flag1) a=temp1;
      if(flag2) b=temp2;
   }while(next_permutation(num.begin(),num.end()));
   cout<<abs(a-b)<<endl;
   return 0;
}
