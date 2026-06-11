#include<iostream>
#include<algorithm>
using namespace std;
int a[1000];
int main(){
	int n;
	while(true){
		cin>>n;
		if(!n)break;
		for(int i=0;i<n;i++)cin>>a[i];
		sort(a,a+n);
		int ret=1145141919;
		for(int i=0;i<n-1;i++)ret=min(ret,a[i+1]-a[i]);
		cout<<ret<<endl;
	}
	return 0;
}