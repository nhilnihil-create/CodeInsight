#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int k;
int n;
int a[2000005];

int main(){
	cin>>k>>n;
	int dis=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		dis = max(dis,a[i]-a[i-1]);
	}
	dis = max(dis,a[1]+k-a[n]);
	cout<<k-dis<<endl;
	
	return 0; 
} 