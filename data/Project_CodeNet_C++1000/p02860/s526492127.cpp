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
  
  int n;
  cin>>n;
  string s;
  cin>>s;
  string s1,s2;
  int i;
  for(i=0;i<n/2;i++){
  	s1=s1+s[i];
  	
  }
  for(i=n/2;i<n;i++){
  	s2=s2+s[i];
  }
  
  string f1=s1+s1;
  string f2=s2+s2;
  if(f1==s){
  	cout<<"Yes"<<endl;
  }
  
  else if(f2==s){
  	cout<<"Yes"<<endl;
  	
  }
  
  else{
  	cout<<"No"<<endl;
  }
  
  return 0;
}