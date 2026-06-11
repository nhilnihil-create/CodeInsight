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
#define dd double
using namespace std;
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  int w[n];
  int i;
  for(i=0;i<n;i++){
     cin>>w[i];
  }
  
  vector<int> v;
  int s1,s2;
  int t;
  for(t=0;t<n;t++){
  	s1=0;
  	s2=0;
  	for(i=0;i<=t;i++){
  		s1=s1+w[i];
	  }
    for(i=t+1;i<n;i++){
    	s2=s2+w[i];
	}
  	
   v.push_back(abs(s1-s2));
  	
  }
  
  sort(v.begin(),v.end());
  cout<<*v.begin()<<endl;
  
  return 0;
}