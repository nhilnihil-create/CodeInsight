#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n;
	cin>>n;
	int a[n]={};
	for(int i=0; i<n; i++){
		int b;
		cin>>b;
		a[b-1]=i+1;
	}
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}