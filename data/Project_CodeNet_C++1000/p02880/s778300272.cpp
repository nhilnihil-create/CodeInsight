#include<bits/stdc++.h>
using namespace std;
int check(int n){
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			if(i*j==n)return 1;
		}
	}
	return 0;
}
int main(){
	int n;
	cin>>n;
	if(check(n))cout<<"Yes";
	else cout<<"No";
	return 0;
}