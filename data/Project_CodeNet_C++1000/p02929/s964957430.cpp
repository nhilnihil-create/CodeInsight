#include <bits/stdc++.h>
#define fto(i,a,b) for(int i=a; i<=b; ++i)
#define fdto(i,a,b) for(int i=a; i>=b; --i)
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define st first
#define nd second
#define maxn 200005
#define Ntu ""

using namespace std;
const int base = 1e9+7;
int n;
char s[maxn];
ll d[maxn], r[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    //freopen(Ntu".inp","r",stdin);
    //freopen(Ntu".out","w",stdout);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    fto(i,1,n*2) cin >> s[i];
    fto(i,1,n*2)
    {
		d[i]=d[i-1];
		if(s[i]==s[i-1]) d[i] ^= 1;
	}
	fdto(i,n*2,1)
	{
		if(d[i]==1) r[i]=r[i+1]+1;
		else r[i]=r[i+1]-1;
	}
	ll rs = 1;
	fto(i,1,n*2) if(r[i] < 0)
    {
        rs = 0;
        break;
    }
	if(r[1] != 0 || s[1] == 'W') rs = 0;
	fto(i,1,n*2) if(!d[i]) rs = 1ll*rs*(r[i]+1)%base;
	fto(i,1,n) rs = rs*i%base;
	cout << rs;
    return 0;
}
