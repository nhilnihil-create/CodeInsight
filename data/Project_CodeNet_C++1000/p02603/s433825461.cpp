#include <bits/stdc++.h>
using namespace std; 
int n;
long long a[85];
int main() {
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long nw=1000;
	long long cnt=0;
	for(int i=0;i<n-1;i++){
		//cout<<nw<<' '<<cnt<<endl;
		nw+=cnt*a[i];
		cnt=0;
		if(a[i]>=a[i+1])continue;
		cnt+=nw/a[i];
		nw%=a[i];
	}
	nw+=cnt*a[n-1];
	cout<<nw<<endl;
    return 0; 
}/*
*/