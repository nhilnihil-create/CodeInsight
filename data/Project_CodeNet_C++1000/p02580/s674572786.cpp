#include<bits/stdc++.h>
#define int long long int
using namespace std;
int32_t main()
{
	int a, b, c; cin >> a >> b >> c;
	int x[c + 50], y[c + 50], mx = 0, my = 0, cntx[a + 50] = {0}, cnty[b + 50] = {0};
	for(int i=0; i<c; i++)
	{
		cin >> x[i] >> y[i];
		cntx[x[i]] ++; mx = max(mx, cntx[x[i]]);
		cnty[y[i]] ++; my = max(my, cnty[y[i]]);
	}
	int t1 = 0, t2 = 0;
	for(int i=1; i<=a; i++) if(cntx[i] == mx) t1 ++;
	for(int i=1; i<=b; i++) if(cnty[i] == my) t2 ++;
	int t = t1 * t2;
	for(int i=0; i<c; i++)
	{
		if(cntx[x[i]] == mx && cnty[y[i]] == my) t --;
	}
	if(t) cout << mx + my;
	else  cout << mx + my - 1;
	cout << '\n';
	return 0;
}