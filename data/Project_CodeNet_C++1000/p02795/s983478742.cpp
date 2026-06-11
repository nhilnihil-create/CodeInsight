#include<bits/stdc++.h> 

using namespace std;

int main(){ 
	cin.tie(0);
	ios::sync_with_stdio(0);
	int h,w,n;
	cin>>h>>w>>n;
	h=max(w,h);
	int val=n/h+(n%h!=0);
	cout<<val;

	return 0;
}

