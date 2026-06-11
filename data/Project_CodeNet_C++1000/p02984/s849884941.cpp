#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
ll a[N],b[N],num[N];
int x[100][100];
int n,m,k;
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%lld",&a[i]);
    }
    for(int i=1; i<=n; i++)
    {
        if(i%2==1)
            b[1]+=a[i];
        else
            b[1]-=a[i];
    }
    for(int i=2;i<=n;i++)
	{
		b[i]=2*a[i-1]-b[i-1];
	}
	 for(int i=1;i<=n;i++)
	{
		cout<<b[i]<<" ";
	}
	
 
    
    return 0;
}