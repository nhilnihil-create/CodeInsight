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
  
  int p,q,r;
  cin>>p>>q>>r;
  int a[3];
  a[0]=p;
  a[1]=q;
  a[2]=r;
  int i,j;
  int smallest=a[0]+a[1];
  for(i=0;i<3;i++){
  	for(j=0;j<3;j++){
  		if(i!=j){
  			if(smallest>a[i]+a[j]){
  				smallest=a[i]+a[j];
			  }
		  }
  		
	  }
  }
  
  cout<<smallest<<endl;
  
  
  
  return 0;
}