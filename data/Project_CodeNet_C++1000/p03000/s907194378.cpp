#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
 int N,X;
 cin>>N>>X;

 int L[N+1];

 for(int i=0;i<N;i++)
 {
     cin>>L[i];
 }
 int D[N+1];
 D[0]=0;
 for(int i=1;i<=N;i++)
 {
     D[i]=D[i-1]+L[i-1];


 }
 long long sum=0;
 for(int i=0;i<N+1;i++)
 {
     if(D[i]<=X)
     {
         sum++;
     }
 }

 cout<<sum<<endl;



}





