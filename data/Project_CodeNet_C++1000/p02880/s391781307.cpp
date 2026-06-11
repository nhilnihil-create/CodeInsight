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
  int i;
  for(i=1;i<10;i++){
  	int j;
  	for(j=1;j<10;j++){
  		
  		int p=i*j;
  		if(p==n){
  			cout<<"Yes"<<endl;
  			return 0;
		  }
  		
  		
	  }
  	
  }
  
    cout<<"No"<<endl;
  
  
  return 0;
}