//https://atcoder.jp/contests/nomura2020/tasks/nomura2020_d
#include<bits/stdc++.h>
using namespace std;
#define nn 65536*16
char str[nn];
signed main(){
	scanf("%s",str);
	int n=strlen(str);for(int i=0;i<n;i++) if(str[i]=='?') str[i]='D';
	printf("%s",str);
	return 0;
} 