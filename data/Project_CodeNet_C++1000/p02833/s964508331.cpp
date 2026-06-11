#include<bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	cin>>n;
	if(n%2) cout<<0;
	else{
		long long two = 0;
		long long five = 0;
		long long curr = 2;
		while(curr<=n){
			two+=n/curr;
			curr*=2;
		}
		curr = 10;
		while(curr<=n){
			five+=n/curr;
			curr*=5;
		}
		cout<<min(five,two);
	}
}