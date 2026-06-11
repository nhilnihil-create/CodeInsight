#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h> 
#include<math.h>


using namespace std;
typedef long long ll;


int main(){
	int n,m=0;
	cin>>n;
	char a[n];
	for(int i=0;i<n;i++) 
		cin>>a[i];
	for(int i=0;i<n;i++) 
	{if(a[i]=='A'&&a[i+1]=='B'&&a[i+2]=='C')  m+=1;
	}
	cout<<m;
	
	

	 

	
	return 0;
}



