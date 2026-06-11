#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
 
using namespace std;

long long gcd(long long a, long long b){
	if(a%b==0)return b;
	else return gcd(b,a%b);
}
int main()
{ 
	int cnt=1;
	long long n,m;
	cin>>n>>m;
	long long arr [100000];
	for(int i=0;i<100000;i++)arr[i]=-1;
	for(int i=0;i<n;i++)cin>>arr[i];
	
	for(int i=0;i<40;i++){
		if(arr[0]%2!=0)break;
		arr[0]=arr[0]/2;
		cnt=cnt*2;
	}
	for(int i=1;i<n;i++){
		int cmd=1;
		for(int j=0;j<40;j++){
			if(arr[i]%2!=0)break;
			arr[i]=arr[i]/2;
			cmd=cmd*2;
		}
		if(cmd!=cnt){cout<<"0"<<endl;return 0;}
	}
	long long gt=1;
	for(int i=0;i<n;i++){
		gt=gt*arr[i]/gcd(gt,arr[i]);
	}
	gt=gt*cnt/2;
	if(gt>m){
		cout<<"0"<<endl;
		return 0;
	}
	cout<<((m/gt)+1)/2<<endl;
	return 0;
}


	
