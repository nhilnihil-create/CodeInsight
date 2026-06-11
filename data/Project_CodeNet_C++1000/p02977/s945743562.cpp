/*
* @Author: wxyww
* @Date: 2020-03-27 15:45:46
* @Last Modified time: 2020-03-27 16:41:26
*/
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstring>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;

ll read() {
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}

int main() {
	int n = read(),m = 1;
	while(m - 1 <= n) m <<= 1;
	m = (m >> 1) - 1;
	if(n == m + 1 || n == 1) {
		puts("No");return 0;
	}
	puts("Yes");
	for(int i = 1;i < m;++i) printf("%d %d\n%d %d\n",i,i + 1,n + i,n + i + 1);
	printf("%d %d\n",m,n + 1);
	if(n != m) printf("1 %d\n%d %d\n",m + n + 1,m + 1,m + n + 2);

	for(int i = m + 2;i <= n;++i) printf("%d %d\n%d %d\n",i + n - 1,i ,i - m - 1,i + n);

	return 0;
}