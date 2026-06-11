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
#define dd double
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
   
  string s;
  cin>>s;
  if(s=="Sunny"){
  	cout<<"Cloudy"<<endl;
  } 
  
  else if(s=="Cloudy"){
  	cout<<"Rainy"<<endl;
  }
  
  else{
  	cout<<"Sunny"<<endl;
  }
 
  return 0;
}