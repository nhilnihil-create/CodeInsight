#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 100010
#define NO !printf("No\n")
#define YES !printf("Yes\n")
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,a[N],cnt[5],num[5],tot;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		bool ok=false;
		for(int j=1;j<=tot;++j){
			if(num[j]==a[i]){
				++cnt[j];
				ok=true;
				break;
			}
		}
		if(!ok){
			++tot;
			if(tot>3)return NO;
			num[tot]=a[i];
			cnt[tot]=1;
		}
	}
	if(tot==1&&num[1]==0)return YES;
	if(tot==2){
		if(!num[1]&&2*cnt[1]==cnt[2])return YES;
		if(!num[2]&&2*cnt[2]==cnt[1])return YES;
	}
	if(tot^3||cnt[1]^cnt[2]||cnt[2]^cnt[3])return NO;
	return num[1]^num[2]^num[3]?NO:YES;
	return 0;
}


