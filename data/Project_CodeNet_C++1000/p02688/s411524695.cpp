#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;cin>>n>>k;
	int ls[n+1]={};
	while(k--){
		int d;cin>>d;
		while(d--){
			int a;cin>>a;
			if(!ls[a]){ n--;ls[a]=1;}
		}
	}
	cout<<n;
}
