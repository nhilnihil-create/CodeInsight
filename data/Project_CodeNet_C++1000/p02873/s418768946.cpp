#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 500050
inline int read(){
	int x=0,f=1;
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
int n,ans[N];
char s[N];
ll tot;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1)+1;
	s[0]='>',s[n]='<';
	for(int i=1;i<=n;++i){
		if(s[i-1]=='>'&&s[i]=='<'){
			ans[i]=0;
			for(int j=i-1;j>=1;--j){
				if(s[j]^'>')break;
				ans[j]=max(ans[j],ans[j+1]+1);
			}
			for(int j=i+1;j<=n;++j){
				if(s[j-1]^'<')break;
				ans[j]=max(ans[j],ans[j-1]+1);
			}
		}	
	}
	for(int i=1;i<=n;++i){
		tot+=ans[i];
	}
	printf("%lld\n",tot);
	return 0;
}

