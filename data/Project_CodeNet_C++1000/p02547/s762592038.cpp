#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<queue>
#include<stack>
#include<map>
#include<math.h>
using namespace std;
 
 
 
int main()
{
	
	int n;
	cin>>n;
	int d1[200];
	int d2[200];
	for(int i=0;i<n;i++){
		cin>>d1[i]>>d2[i];
	}
	int flag=0;
	for(int i=0;i<n-2;i++){
		if(d1[i]==d2[i]){
			if(d1[i+1]==d2[i+1]){
				if(d1[i+2]==d2[i+2]){
					flag=1;
					break;
				}
			}
		}
	}
	if(flag==1){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}