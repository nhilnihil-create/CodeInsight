#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000010;
int n,ans,flg,a[MAXN];
char c[MAXN];
int main () {
	scanf("%d%s",&n,c+1);
	for (int i=1;i<=n;i++) {
		a[i]=c[i]-'1';
		if (a[i]==1) {flg=1;}
	}
	if (!flg) {
		for (int i=0;i<=n-1;i++) {
			if (((n-1)&i)==i) {
				ans^=a[i+1];
			}
		}
		printf("%d",ans);
	} else {
		for (int i=1;i<=n;i++) {
			if (a[i]==2) {a[i]=0;}
		}
		for (int i=0;i<=n-1;i++) {
			if (((n-1)&i)==i) {
				ans^=a[i+1];
			}
		}
		printf("%d",ans);
	}
	return 0;
}