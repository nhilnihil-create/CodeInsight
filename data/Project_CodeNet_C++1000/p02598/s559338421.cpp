#include <bits/stdc++.h>

using namespace std;
using lli = long long int;
const lli maxn=1e6+5;
lli n,k;
lli a[maxn];
lli maxi=-1;
bool check(lli m)
{
    lli sl=0;
    for(lli i=0;i<n;i++)
	{
        sl+=a[i]/m;
        if(a[i]%m==0)
		{
			sl-=1;
		}
	}
	return (sl<=k);
}
int findmin()
{
    lli dau=1;
    lli cuoi=maxi;
    lli giua;
    lli m;
    while(dau<=cuoi)
	{
        giua=(dau+cuoi)/2;
        if(check(giua)==true)
		{
			m=giua;
			cuoi=giua-1;
		}
		else
		{
            dau=giua+1;
		}
	}
	return m;
}
void nhap()
{
    //freopen("test.inp","r",stdin);
    cin>>n>>k;
    for(lli i=0;i<n;i++)
	{
        cin>>a[i];
        maxi=max(maxi,a[i]);
	}
	cout<<findmin();
}
int main()
{
    nhap();
}
