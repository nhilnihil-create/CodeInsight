#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline int read(){
	int _s=0,_f=1,_q=getchar();
	while(_q<48||_q>57){if(_q=='-')_f=-1;_q=getchar();}
	while(_q>47&&_q<58)_s=(_s<<3)+(_s<<1)+_q^48,_q=getchar();
	return _s*_f;
}
int a[2020]={1};
const int m=1000000007;
int main(){
	for(int i=3;i<=2000;i++)
		for(int j=3;j<=i;j++)
			a[i]+=a[i-j],a[i]%=m;
	int s;
	cin>>s;
	cout<<a[s];
	return 0;
}
