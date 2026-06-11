#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
constexpr int MX = 200005;
int n, a[MX], b[MX], ans;
int main(){
	scanf("%d", &n);
	rep(i,n) scanf("%d%d", a+i, b+i);
	sort(a, a+n);
	sort(b, b+n);
	if(n % 2) ans = b[n/2] - a[n/2] + 1;
	else ans = b[n/2-1] - a[n/2-1] + b[n/2] - a[n/2] + 1;
	printf("%d\n", ans);
}