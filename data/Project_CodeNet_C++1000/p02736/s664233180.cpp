// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9;

int n;
char s[1000005];
int a[1000005];

signed main(){
	scanf("%d",&n);--n;
	scanf("%s",s); 
	for(int i=0;i<=n;i++)a[i] = s[i]-'1';
	int ans=0;
	for(int i=0;i<=n;i++){
		if((n&i) == i)ans = (ans+a[i])%2;
	}
	if(ans)return puts("1"),0;
	else{
		int fg = 1;
		for(int i=0;i<=n;i++)if(a[i] == 1)fg=0;
		if(!fg)puts("0");
		else{
			int x=0;
			for(int i=0;i<=n;i++)a[i] >>= 1;
			for(int i=0;i<=n;i++)
				if((n&i) == i)x = (x+a[i])%2;
			if(x)return puts("2"),0;
			else puts("0");
		}
	}

	return 0;
}

