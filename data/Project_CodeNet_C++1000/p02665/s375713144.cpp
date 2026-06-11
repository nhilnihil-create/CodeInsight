/*The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep,
And miles to go before I sleep.*/

//PRABHJOT SINGH A.K.A. PRABHI
//~~~~~conquizztador~~~~~


#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define fi first
#define se second
#define MOD 100000000
const int maxn= 100010;
lli a[maxn];
lli pre[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=0;lli leafnahi=1ll,res=0ll;
    cin>>n;
    for(int i=0;i<=n;++i)
    {
    	cin>>a[i];
    	pre[i]=a[i];
    }
    for(int i=n;i>0;--i)
    	pre[i-1]+=pre[i];
    for(int i=0;i<=n;++i)
    {
    	pre[i]=min(pre[i],leafnahi);
    	leafnahi-=a[i];
    	if(leafnahi<0ll)
    	{
    		cout<<"-1";
    		return 0;
    	}
    	leafnahi*=2ll;
    	if(leafnahi>(lli)(1e18))
    		leafnahi=(lli)(1e18);
    }
    for(int i=0;i<=n;++i)
    	res+=pre[i];
    cout<<res<<endl;
}