#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define gc getchar
inline ll read(){
    char ch=gc();
    while (!isdigit(ch)) ch=gc();
    return ch-'0';
}
ll a[1111111],n,b[1111111];
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++) a[i]=read(); 
	n--;
	for (int i=1;i<=n;i++) b[i]=abs(a[i+1]-a[i]);
	for (int i=1;i<=n;i++) a[i]=b[i];
	ll _=0;
	bool flag1=0;
	for (int i=1;i<=n;i++){
		_=(_+((((n-1)&(i-1))==i-1)?a[i]:0))&1;
		flag1|=(a[i]==1);
	}
	if (_==1) puts("1");
	else{
		if (flag1) puts("0"); 
		else{
			_=0;
			for (int i=1;i<=n;i++){
				_=(_+((((n-1)&(i-1))==i-1)?a[i]/2:0))&1;
			}
			puts(_==0?"0":"2");
		}
	}
    return 0;
}
