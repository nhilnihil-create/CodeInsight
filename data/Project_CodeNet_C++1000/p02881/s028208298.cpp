#include<bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	cin>>n;
	long long minmove = n-1;
	for(long long i=1; i*i<=n; i++){
		if(n%i==0){
			minmove = min(minmove,(i-1)+(n/i-1));
		}
	}
	cout<<minmove;
}