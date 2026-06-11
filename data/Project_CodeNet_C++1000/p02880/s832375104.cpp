#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin>>n;
	for(int i=1;i<=9;i++){
		for(int j=i;j<=9;j++){
			int s=i*j;
			if(n==s){
				cout<<"Yes";
				return 0;
			}	
			else continue;
		}
	}
	cout<<"No";
	return 0;
}