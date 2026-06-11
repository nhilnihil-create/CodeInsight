#include <bits/stdc++.h>
using namespace std;
int main(){
   long long int N,A,B,tot;
   cin>>N>>A>>B;
   long long int sum=A+B;
   long long int Q=A*(N/sum);
   long long int R=N%sum;
   tot=Q+min(R,A);
   long long int power = pow(10,18);
  if(N>=1&&A>=0&&B>=0&&sum>0&&N<=power&&sum<=power){
   cout<<tot;
  }
   return 0;
   
}