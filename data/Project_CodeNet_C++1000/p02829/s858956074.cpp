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
  if(a==1&&b==2){
  	
  	cout<<"3"<<endl;
  	
  }
  
  else if(a==2&&b==1){
  	
  	cout<<"3"<<endl;
  	
  }
  
  else if(a==2&&b==3){
  	
    cout<<"1"<<endl;
  	
  }
  
  else if(a==3&&b==2){
  	cout<<"1"<<endl;
  	
  }
  
  else if(a==1&&b==3){
  	cout<<"2"<<endl;
  }
  
  
  else if(a==3&&b==1){
  	cout<<"2"<<endl;
  	
  }
  
  return 0;
}