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
  string t;
  cin>>s>>t;
  string f;
  int i;
  for(i=0;i<n;i++){
  	
  	f=f+s[i]+t[i];
  	
  }
  
   cout<<f<<endl;
  
  return 0;
}