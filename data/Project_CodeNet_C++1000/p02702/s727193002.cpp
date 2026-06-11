#include<bits/stdc++.h>
using namespace std;
int k[2020],f[2000005],a[2000005],g[2000005];
long long sum;
int main() {
	string s;
	cin>>s;
	int n=s.size();
	
	for(int i=0;i<n;i++){
		a[i+1]=s[i]-'0';
	}
	int l=1;
	for(int i=n;i>=1;i--){
		g[i]=l;
		l*=10;
		l%=2019;
	}
	for(int i=n;i>=1;i--){
		f[i]=(f[i+1]+a[i]*g[i])%2019;
		k[f[i]]++;
	}
	sum=k[0];
	sum+=(k[0]*(k[0]-1)/2);
	for(int i=1;i<=2018;i++){
		sum+=(k[i]*(k[i]-1)/2);
	}
	cout<<sum;
	return 0;
}