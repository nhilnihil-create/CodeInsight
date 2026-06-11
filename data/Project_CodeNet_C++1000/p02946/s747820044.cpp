#include <bits/stdc++.h>
using namespace std;

int main(){
	int k,x;
	cin>>k>>x;
	for(int i=x-k+1;i<x;i++){
		cout<<i<<" ";
	}
	for(int j=x;j<k+x-1;j++){
		cout<<j<<" ";
	}
	cout<<k+x-1;
}
