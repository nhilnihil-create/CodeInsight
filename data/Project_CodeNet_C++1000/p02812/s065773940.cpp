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
  int i;
  int count=0;
  for(i=0;i<n-2;i++){

  	if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C'){
  	   count++;	
  	   i+=2;
	}

  }
  
  cout<<count<<endl;
  
  return 0;
}