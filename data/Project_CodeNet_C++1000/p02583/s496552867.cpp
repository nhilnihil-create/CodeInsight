/*  CREATED BY
    Stream_Cipher
    13-sep-2020
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
#define debug1(a) cout<<#a<<"="<<(a)<<"\n"
#define debug2(a,b) cout<<#a<<"="<<(a)<<","<<#b<<"="<<(b)<<"\n"
#define debug3(a,b,c) cout<<#a<<"="<<(a)<<","<<#b<<"="<<(b)<<","<<#c<<"="<<(c)<<"\n"
#define fix_precision(n) cout<<fixed<<setprecision(n)
#define all(a) a.begin(),a.end()
const double pi=acos(-1.0);
int inf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
const int mx=5*1000000;//5*64M bit ->5*8M byte ->40MB size for long long int (64 bit)
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
        int n;
        cin>>n;
        vector<int>a(n);
        for(auto &i:a)
        	cin>>i;
        // sort(all(a));
        int ans=0;
        for(int i=0;i<n;i++)
        {
        	for(int j=i+1;j<n;j++)
        	{
        		for(int k=j+1;k<n;k++)
        		{
        			if(a[i]+a[j]>a[k]&&a[k]+a[j]>a[i]&&a[k]+a[i]>a[j]&&a[i]!=a[j]&&a[j]!=a[k]&&a[k]!=a[i])
        			{
        				// cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;
        				ans++;
        			}
        		}
        	}
        }
        cout<<ans<<endl;
}