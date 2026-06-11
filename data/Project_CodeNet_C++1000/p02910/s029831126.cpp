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
  int i;
  for(i=0;i<s.size();i++){
  	  if(i%2==0){
  	 if(s[i]!='R'&&s[i]!='U'&&s[i]!='D'){
  	 	cout<<"No"<<endl;
  	 	break;
	   }
    }
	  
	  else if(i%2!=0){ 
	  if(s[i]!='L'&&s[i]!='U'&&s[i]!='D'){
	  	cout<<"No"<<endl;
	  	break;
	  } 
	   
	     	
	 }
  }
  
  if(i==s.size()){
  	cout<<"Yes"<<endl;
  }
   
  return 0;
}