#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<unordered_map>
#include<bits/stdc++.h>
#define ll long long 
#define d double
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
   
  int a,b;
  cin>>a>>b;
  int A=a;
  int B=b;
  string s1 =to_string(a);
  string s2= to_string(b);
  string f1,f2;
  
  while(a--){
  	f1=f1+s2;
  }
  
  while(b--){  	
  	f2=f2+s1;
  }
  

   
  if(A<B){
  	
  	cout<<f2<<endl;
  	
   }  
   
   else if(B<A){
   	
   	
   	cout<<f1<<endl;
   	
   }
   
   
   else if(A==B){
   	
   	cout<<f1<<endl;
   	
   }
   
  return 0;
}