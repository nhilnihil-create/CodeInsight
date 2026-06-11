#include<iostream>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#define ll long long 
#define d double
using namespace std;

int main()
{
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a[3];
    int i;
    for(i=0;i<3;i++){
    	cin>>a[i];
	}
	int count=0;
	for(i=0;i<3;i++){
	  int j;
	  for(j=i+1;j<3;j++){
	  	if(a[i]==a[j]){
	  		count++;
		  }	
	  }	
	}
	
	if(count==1){
		cout<<"Yes"<<endl;
	}
	
	else{
		cout<<"No"<<endl;
		
	}
    return 0;   
}