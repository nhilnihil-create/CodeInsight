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
     
    int n,r;
    cin>>n>>r;
    
    if(n>=10){
     	cout<<r<<endl;
    }
  
	else{	
		cout<<r+100*(10-n)<<endl;	
	}
     
    return 0;
    
}