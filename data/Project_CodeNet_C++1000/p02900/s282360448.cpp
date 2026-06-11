#include<bits/stdc++.h>
using namespace std;
const int M=1e6+5;

int cnt=0,c2=0,c3=1,types[M];
long long prime[M],a,b,g,divs[M],tot=0;
bool isp[M];

void sieve(int p){
	memset(isp,true,sizeof(isp));
	isp[0]=isp[1]=false;
	for (int i=2;i<=p;i++){
		if (isp[i]){
			prime[++cnt]=i;
		}
		for (int j=1;j<=cnt && i*prime[j]<=p;j++){
			isp[i*prime[j]]=false;
			if (i%prime[j]==0) break;
		}
	}
}
long long gcd(long long a,long long b){
	return b==0?a:gcd(b,a%b);
}

int main(){
	sieve(1000000);
	cin>>a>>b;
	g=gcd(a,b);
	for (int i=1;i<=cnt;i++){
		while (g%prime[i]==0){
			divs[++c2]=prime[i];
			g/=prime[i];
		}
	}
	if (g!=1) divs[++c2]=g;
	long long os=0;
	for (int i=1;i<=c2;i++){
		if (divs[i]!=os){
			os=divs[i];
			c3++;
			types[c3]=1;
		} else {
			types[c3]++;
		}
	}
	cout<<c3;
	return 0;
}
