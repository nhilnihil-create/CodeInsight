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
  
  int n,k;
  cin>>n>>k;
  int a[n];
  int i;
  int count=0;
  for(i=0;i<n;i++){
  	cin>>a[i];
  	if(a[i]>=k){
  		count++;
  		
	  }
  }

  cout<<count<<endl;

  return 0;
}