#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
   ll a[5];
   for(int i=0;i<5;i++)
   cin>>a[i];
   for(int i=0;i<5;i++)
   {
       if(a[i]==0)
       {
           cout<<i+1<<endl;
           break;
       }
   }
}