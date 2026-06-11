#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;
using lli = long long int;
const lli maxn=1e6+5;
lli n,d;
lli dem;

void nhap()
{
    //freopen("test.inp","r",stdin);
    {
        cin>>n>>d;
        for(lli i=1;i<=n;i++)
		{
            lli u,v;
            cin>>u>>v;
            if(sqrt(u*u+v*v) <=d)
			{
                dem++;
			}

		}

		cout<<dem;
    }
}
int main()
{
    nhap();
}
