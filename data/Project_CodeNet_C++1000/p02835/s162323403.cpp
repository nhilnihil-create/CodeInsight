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
  
  int a1,a2,a3;
  cin>>a1>>a2>>a3;
  int s=0;
  s=s+a1+a2+a3;
  if(s>=22){
  	cout<<"bust"<<endl;
  	
  }
  
  else{
  	
  	cout<<"win"<<endl;
  }
  
  return 0;
}