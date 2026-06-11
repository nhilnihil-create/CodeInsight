#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h> 

#include<math.h>//pow(a,b)函数 ,abs(绝对值）函数 

using namespace std;
typedef long long ll;


int main(){
	int n,x=0,y=0;
	cin>>n;
	int a[n],b[n];
	for(int i=0;i<n;i++) 
		cin>>a[i];
	for(int j=0;j<n;j++) 
		cin>>b[j];
	do{x+=1;
	}while( next_permutation (a,a+n));
	do{y+=1;
	}while( next_permutation (b,b+n));
	
	cout<<abs(x-y);
	
	

	 

	
	return 0;
}



