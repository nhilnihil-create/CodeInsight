#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const long long int MAX=1e3;
map<long long int , long long int >cnt;
long long int prime[MAX]={1};
void compute(){
	long long int i ,j,k;
	for(i=1;i<MAX;i++)
		prime[i]=1;
	for(i=2;i*i<MAX;i++){
		if(prime[i]){
			for(j=2*i;j<MAX;j+=i)
				prime[j]=0;
		}
	}
}
int main(){
	long long int a  ,b ,c ,n ,i ,j;
	cin>>n;
	c=n;
	compute();
//	cout<<"\n";
	cout<<n<<':';
	for(i=2;i*i<=n;i++){
		while(n%i==0){
			cout<<" "<<i;
//			cnt[n/i]++;
			n=n/i;
		}
	}
	if(n!=1)
		cout<<" "<<n;
	cout<<"\n";
}
