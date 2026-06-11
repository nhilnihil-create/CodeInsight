#include <iostream>

using namespace std;

const int MOD = 1000000007;
long long fr[2001];
int main(){
	
	long long n,k;
	cin>>n>>k;
	int a[n];
	long long res = 0;
	for(int i =0;i<n;i++){
		cin>>a[i];
		fr[a[i]]++;
		long long ma = 0;
		//cout<<i<<endl;
		for(int j = a[i]+1;j<=2000;j++)ma += fr[j];
		//cout<<i<<endl;
		res = (res + ma*k)%MOD;
	}
	long long s = 0;
	long long sk = (k * (k-1) /2)%MOD;
	for(int i=1;i<=2000;i++){
		res  = (res + fr[i] * s * sk) %MOD;
		s+=fr[i];
	}
	cout<<res<<endl;
		
	return 0;
}