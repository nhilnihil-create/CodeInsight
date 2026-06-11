
#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	cin >> s;
	long long n=s.size();
	long long mod=2019;
	vector<long long> t(n+1,0);
	t[n]=0;
	long long b=1;
	vector<long long> c(2019,0);
	t[n]=0;
	c[0]++;
	for(long long i=1;i<=n;i++){
		t[n-i]=(t[n-i+1]+b*(s[n-i]-'0'))%mod;
		c[t[n-i]]++;
		b=(b*10)%mod;
	}
	long long ans=0;
	for(long long i=0;i<2019;i++){
		ans+=c[i]*(c[i]-1)/2;
	}
	cout << ans << endl;
}
