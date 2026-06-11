#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define cs const 
#define fr first 
#define se second
#define ls (now<<1)
#define rs (now<<1|1)
#define mid ((l+r)>>1)
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define low(i) (i&(-i))
#define par pair<int,int>
#define cn(x) memset(x, 0, sizeof(x))
#define rep(i, x, y) for(int i=x; i<=y; ++i)
#define sep(i, x, y) for(int i=x; i>=y; --i)
#define fore(i, x) for(int i=fir[x]; i; i=nex[i])

cs int G = 3;
cs int ff = 2e6 + 1;
cs int inf = 1e9 + 1;
cs int base = 2333;
cs int mod = 1e9 + 7;

int A[ff][2], h, w, m, x[ff], y[ff], mx1, mx2, s1, s2, s;
signed main()
{
	cin >> h >> w >> m;
	rep(i, 1, m) cin >> x[i] >> y[i], A[x[i]][1] ++, A[y[i]][2] ++;
	rep(i, 1, max(h, w)) if(A[mx1][1] < A[i][1]) mx1 = i;
	rep(i, 1, max(h, w)) if(A[mx2][2] < A[i][2]) mx2 = i; 
	rep(i, 1, h) if(A[mx1][1] == A[i][1]) s1 ++;
	rep(i, 1, w) if(A[mx2][2] == A[i][2]) s2 ++;
	rep(i, 1, m) if(A[x[i]][1] == A[mx1][1] && A[y[i]][2] == A[mx2][2]) s ++;
	cout << A[mx1][1] + A[mx2][2] - (s1 * s2 == s);
}