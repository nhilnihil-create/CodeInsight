#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define sigma_size 30
#define max_size (int)(3e5+10)
#define MAX (int)(1e5+7)
int qread()
{
	char c; int s=0,t=1; while ((c=getchar())<'0' || c>'9') (c=='-' && (t=-1));
	do s=s*10+c-'0'; while ((c=getchar())>='0' && c<='9'); return s*t;
}

int a[max_size];
LL sum[max_size] , pre[max_size];
int n;
vector <int> v;
bool check( int k , int lim )
{
	k -= ( pre[n] - pre[lim-1] );
	if ( k <= 0 ) return true;
	return sum[lim-1] >= (LL)k*lim;
}
int main ()
{
	n = qread();
	for ( int i = 1 ; i <= n ; i++ ){
		int x = qread();
		a[x]++;
	}
	for ( int i = 1 ; i <= n ; i++ )	pre[a[i]]++;
	for ( int i = 1 ; i <= n ; i++ )	
		sum[i] = sum[i-1] + i*pre[i] , pre[i] += pre[i-1];
	
	cout << n << endl;
	for ( int k = 2 ; k <= n ; k++ )
	{
		if ( k > pre[n] )
		{
			cout << "0" << endl;
			continue;
		}
		int l = 0 , r = n;
		while ( l < r )
		{
			int mid = l + r + 1 >> 1;
			if ( check(k,mid) ) l = mid;
			else r = mid-1;
		}
		cout << l << endl;
	}
}