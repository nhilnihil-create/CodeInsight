#include<bits/stdc++.h>
#define PI 3.1415926535897932384626433832795
#define ll long long
#define MP make_pair
#define IN insert
#define PB push_back
#define fr first
#define se second
#define sf scanf
#define pf printf
#define debug(x) cout<<"---------"<<x<<endl;
#define LEN(a) sizeof(a)/sizeof(a[0])
#define MEM(arr,k) memset(arr,k,sizeof arr)
#define input freopen("input","r",stdin)
#define output freopen("output","w",stdout)

int X8[] = {0, 1, 0, -1, 1, -1, 1, -1};
int Y8[] = {1, 0, -1, 0, 1, -1, -1, 1};
int X4[]={+1,-1,+0,+0};
int Y4[]={+0,+0,+1,-1};

using namespace std;


int main()
{
    int n,k;
    sf("%d %d",&n,&k);
    n = n-k;
    if(k==1)
    {
		pf("0\n");
	}
    else
    {
		pf("%d\n",n);
	}
    
    return 0;
}
