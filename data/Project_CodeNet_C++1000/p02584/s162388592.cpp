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
        int x,k,dis;
        cin>>x>>k>>dis;
        // x=abs(x);
        if(abs(x)/dis>=k)
        	cout<<abs(x)-k*dis<<endl;
        else
        {
        	// cout<<"ASF\n";
        	int mx=abs(x)-(abs(x)/dis)*dis;
        	int mn=abs(mx-dis);
        	int ans;
        	k-=abs(x)/dis;
        	if(k%2==0)
        		ans=mx;
        	else
        		ans=mn;
        	cout<<ans<<endl;
        }
}