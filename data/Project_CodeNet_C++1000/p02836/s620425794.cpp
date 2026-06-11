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
  string s;
  cin>>s;
  size_t n=s.size();
  int i=n-1;
  int j=0;
  int count=0;
  while(i>j){
  	
  	if(s[j++]!=s[i--]){
  		count++;
  		
	  }
  	
  }
   cout<<count<<endl;

  return 0;
}
