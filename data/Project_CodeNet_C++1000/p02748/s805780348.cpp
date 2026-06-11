#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
 int A,B,M;
 cin>>A>>B>>M;
 int a[A];

 int mina=INT_MAX;int minb=INT_MAX ;int minc=INT_MAX;

 for(int i=0;i<A;i++)
 {
     cin>>a[i];
     if(a[i]<mina)
         mina=a[i];
 }
 int b[B];
 for(int i=0;i<B;i++)
 {
     cin>>b[i];
     if(b[i]<minb)
         minb=b[i];
 }
 int c[M];
 for(int i=0;i<M;i++)
 {
     int x,y,t;
     cin>>x>>y>>t;
     c[i]=a[x-1]+b[y-1]-t;
     if(minc>c[i])
         minc=c[i];
 }
 cout<<min(mina+minb,minc);
}