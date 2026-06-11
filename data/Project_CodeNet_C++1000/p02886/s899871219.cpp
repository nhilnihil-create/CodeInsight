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
  int n;
  cin>>n;
  int d[n];
  int i;
  for(i=0;i<n;i++){
  	cin>>d[i];
  }
  
  int s=0;
  for(i=0;i<n-1;i++){
  	int j;
  	for(j=i+1;j<n;j++){
  		int p=d[i]*d[j];
  		s=s+p;
	  }

  }
  
  cout<<s<<endl;
  
  
  return 0;
}