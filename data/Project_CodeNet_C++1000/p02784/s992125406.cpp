#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<unordered_map>
#define ll long long 
#define d double
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int h,n;
  cin>>h>>n;
  int a[n];
  int i;
  int s=0;
  for(i=0;i<n;i++)
  {
  	
  	cin>>a[i];
  	s=s+a[i];
  	
  }
  
  if(h>s){
  	cout<<"No"<<endl;
  }
  
  else{
  	
  	cout<<"Yes"<<endl;
  }
  
  
  return 0;
}