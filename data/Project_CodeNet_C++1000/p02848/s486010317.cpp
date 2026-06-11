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
  size_t m=s.size();
  int i;
  for(i=0;i<m;i++){
  	
  	int p=int(s[i])+n;
  	if(p>90){
  		
  	   s[i]=p-26; 		
  		
	  }
	  
	else{
		
		s[i]=int(s[i])+n;
		
	} 
  	
  }
  
  
   cout<<s<<endl;
  
  
  return 0;
}