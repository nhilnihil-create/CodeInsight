#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define sigma_size 30
#define max_size (int)(1e5+10)
#define MAX (int)(1e5+7)
int qread()
{
	char c; int s=0,t=1; while ((c=getchar())<'0' || c>'9') (c=='-' && (t=-1));
	do s=s*10+c-'0'; while ((c=getchar())>='0' && c<='9'); return s*t;
}

int n;
LL a[max_size];
LL ans[max_size];
LL sum;
int main ()
{
    n = qread();
    for ( int i = 1 ; i <= n ; i++ )
    {
        LL x = qread();
        a[i] = x*2;
        sum += x;
    }
    ans[1] = sum;
    for ( int i = 2 ; i <= n ; i+=2 )
        ans[1] -= a[i];
    for ( int i = 2 ; i <= n ; i++ )
        ans[i] = a[i-1]-ans[i-1];
    for ( int i = 1 ; i <= n ; i++ )
    {
        cout << ans[i];
        if ( i < n ) cout << " ";
        else cout << endl;
    }
}