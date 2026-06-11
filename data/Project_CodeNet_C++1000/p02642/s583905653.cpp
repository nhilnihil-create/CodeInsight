/*  CREATED BY
    STREAM_CIPHER
    07-sep-2020
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
int vis[mx];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif
        int n;
        cin>>n;
        vector<int>a(n);
        for(auto &i:a)
        	cin>>i,vis[i]++;
        int ans=0;
        for(int i=0;i<n;i++)
        {
        	vis[a[i]]--;
        	bool fnd=false;
        	for(int j=1;j<=sqrt(a[i]);j++)
        	{
        		if(a[i]%j==0)
        		{
        			// debug1(j);
        			if(vis[j]!=0)
        			{
        				fnd=true;
        				break;
        			}
        			if(a[i]/j!=j)
        			{
        				if(vis[a[i]/j]!=0)
        				{
        					fnd=true;
        					break;
        				}
        			}
        		}
        	}
        	if(!fnd)
        		ans++;
        	vis[a[i]]++;
        }
        cout<<ans<<endl;
}