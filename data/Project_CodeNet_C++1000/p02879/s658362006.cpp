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
  if(a>=1&&a<=9&&b>=1&&b<=9){
  	cout<<a*b<<endl;
  	
  }
  
  else{
  	cout<<"-1"<<endl;
  }
  
  
  return 0;
}