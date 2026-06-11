//Author: Fuadul Hasan(fuadul202@gmail.com)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N   = 2e5 + 5;

int main(){
	
	
	int n,k;
	cin>>n>>k;
	int a[n];
	int cnt = 0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i] >= k)cnt++;
	}

	cout<<cnt<<endl;


	

	return 0;
}