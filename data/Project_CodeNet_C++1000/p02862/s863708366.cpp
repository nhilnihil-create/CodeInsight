#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}

int main(){
	int x,y;
	cin>>x>>y;
	if((x+y)%3!=0){
		cout<<0<<endl;
		return 0;
	}

	int a=(2*y-x)/3;
	int b=(x-a)/2;

	if(a<0 || b<0){
		cout<<0<<endl;
		return 0;
	}

	int n=a+b;
	int r=min(a,b);

	long long ans=1;

	for(int i=0;i<r;i++){
		ans*=n;
		ans%=inf;
		n--;
	}

	for(int i=1;i<=r;i++){
		ans*=modinv(i,inf);
		ans%=inf;
	}

	cout<<ans<<endl;

	return 0;
}
