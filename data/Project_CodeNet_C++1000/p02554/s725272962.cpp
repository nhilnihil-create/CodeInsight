#include<bits/stdc++.h>
using namespace std;
long long M = pow(10, 9) + 7;
long long power(long long a, long long b) {
	if (b == 0) return 1;
	if (b % 2) return (a * power(a, b - 1)) % M;
	long long k = power(a, b / 2);
	return (k * k) % M;
}
const int Max=1e6+2;
int Power[Max];
int Fact[Max];
int invF[Max];
void help(){
	Power[0]=0;
	long long p=1;
	long long r=1;
	Fact[0]=1;
	invF[0]=1;
	long long q=1;
	for(long long i=1;i<Max;i++){
		p=(p*9)%M;
		r=(r*8)%M;
		Power[i]=(p-r+M)%M;
		q=(q*i)%M;
		Fact[i]=q;
		invF[i]=power(q,M-2);
	}
}
int solve(){
	long long n,k;
	cin>>n;
	if(n==1) return 0;
	help();
	long long ans=0,x,y,a,b,c;
	a=Fact[n];
	for(int i=1;i<n;i++){
		b=invF[i],c=invF[n-i];
		x=(((b*c)%M)*a)%M;
		int k=n-i;
		y=Power[k];
		ans= (ans+(x*y)%M)%M;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<solve();

}