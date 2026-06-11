#include<iostream>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<math.h>
#define ll long long 
#define d double
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int a[n],b[m];
	int i;
	int j;
	int c1=2;
	int c2=1;
	for(i=0;i<n;i++){
		a[i]=c1;
		c1+=2;
	}
	
	for(i=0;i<m;i++){
		b[i]=c2;
		c2+=2;
	}
	
	int s;
	int count=0;
	for(i=0;i<n;i++){
		s=0;
		for(j=i+1;j<n;j++){
		   s=s+a[i]+a[j];
		   if(s%2==0){
		   	 count++;
		   }
		}
	}
	
	int count2=0;
	for(i=0;i<m;i++){
		s=0;
		for(j=i+1;j<m;j++){
			s=s+b[i]+b[j];
			if(s%2==0){
				count2++;
			}
		}
	}
	
    cout<<count+count2<<endl;
    return 0;
	
}