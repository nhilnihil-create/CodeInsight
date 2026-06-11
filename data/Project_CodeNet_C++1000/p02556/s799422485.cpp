#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=2e5+5;
const int mod=1e9+7;
int a[N];
int b[N];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
	{
        int x,y;
		cin>>x>>y;
        a[i]=x-y;
        b[i]=x+y;
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    int ans=max(a[n]-a[1],b[n]-b[1]);
    cout<<ans<<endl;
    return 0;
}
