#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;



/// Info.
///****************************************************************************************************************************************///
/// author                : BAHAA El-DEEN OSAMA .
/// Problem name          : Q - H and V
/// Method                : brute force
/// Online judge          : vjudge(Contest)
/// Date                  : 8/7/2020
///****************************************************************************************************************************************///
#define ll   long long int



bool a[10][10];
int n,m,k,ans;
char st[10];

int main() {
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;++i) {
		scanf("%s",st+1);
		for (int j=1;j<=m;++j)
		if (st[j]=='#') a[i][j]=1;
	}

	for (int x=0;x<(1<<n);++x)
	for (int y=0;y<(1<<m);++y) {
		int sl=0;
		for (int i=1;i<=n;++i)
		if ((1<<i-1)&x)
			for (int j=1;j<=m;++j)
			if ((1<<j-1)&y)
			if (a[i][j])
			++sl;
		if (sl==k) ++ans;
	}
	printf("%d\n",ans);

	return 0;
}
