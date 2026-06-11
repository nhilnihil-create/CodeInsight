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
  b=b*2;
  if(b<=a){
  	
  	cout<<a-b<<endl;
  	
  }
  
  else{
  	
  	cout<<"0"<<endl;
  }
  
  return 0;
}