#include<bits/stdc++.h>
//#define int long long
#define rep(i, l, r) for(int i = l; i <= r; ++ i)

int read()
{
	char cc = getchar(); int cn(0), flus(1);
	while(cc > '9' || cc < '0') {if(cc == '-') flus = -flus; cc = getchar();}
	while(cc >= '0' && cc <= '9') {cn = cn * 10 + cc - 48; cc = getchar();}
	return cn * flus;
}
 
inline int max(int a, int b)
{
	return (a > b) ? a : b;
}
 
const int MAXN = 3e5 + 10;

struct node
{
	int x, y;
} a[MAXN];

int x, y, m;
int sumx[MAXN], sumy[MAXN];
bool fx[MAXN], fy[MAXN], ok(1);

signed main()
{ 
	int cnt1(0), cnt2(0), cnt3(0);
	x = read(), y = read(), m = read();
	rep(i, 1, m) a[i].x = read(), a[i].y = read(), sumx[a[i].x] ++, sumy[a[i].y] ++;
	int maxx(0), maxy(0);
	rep(i, 1, x) maxx = max(maxx, sumx[i]);
	rep(i, 1, y) maxy = max(maxy, sumy[i]);
	rep(i, 1, x) fx[i] = (sumx[i] == maxx) ? 1 : 0, cnt1 += fx[i];
	rep(i, 1, y) fy[i] = (sumy[i] == maxy) ? 1 : 0, cnt2 += fy[i];
	rep(i, 1, m) 
	{
		if(fx[a[i].x] && fy[a[i].y]) 
		{
			cnt3 ++;
		}
	}	
	int ans(0);
//	printf("cnt1 = %d cnt2 = %d cnt3 = %d \n", cnt1, cnt2, cnt3);
	if(cnt1 * cnt2 == cnt3) ok = 0;
	if(!ok) ans = maxx + maxy - 1;
	else ans = maxx + maxy;
	printf("%d\n", ans);
	return 0;
} 