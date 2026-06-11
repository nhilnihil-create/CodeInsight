/************************************************************************
*                  -> Bismillahir Rahmanir Rahim <-                     *
*                                                                       *
*                                                                       *
*                                                                       *
*                                                                       *
* __________             .___        .__              ____ ________     *
* \______   \_____     __| _/  ______|  |__  _____   /_   |\_____  \    *
*  |    |  _/\__  \   / __ |  /  ___/|  |  \ \__  \   |   | /  ____/    *
*  |    |   \ / __ \_/ /_/ |  \___ \ |   Y  \ / __ \_ |   |/       \    *
*  |______  /(____  /\____ | /____  >|___|  /(____  / |___|\_______ \   *
*         \/      \/      \/      \/      \/      \/               \/   *
*                                                                       *
*                                                                       *
*                                                                       *
*              .=.,                                                     *
*             ;c =\                                                     *
*           __|  _/                                                     *
*         .'-'-._/-'-._                                                 *
*        /..   ____    \                                                *
*       /' _  [<BF>] )  \                                               *
*      (  / \--\_>/-/'._ )                                              *
*       \-;_/\__;__/ _/ _/                                              *
*        '._}|==o==\{_\/                                                *
*         /  /-._.--\  \_                                               *
*        // /   /|   \ \ \                                              *
*       / | |   | \;  |  \ \                                            *
*      / /  | :/   \: \   \_\                                           *
*     /  |  /.'|   /: |    \ \                                          *
*     |  |  |--|   |--|     \_\                                         *
*     / _/   \ |   | /___--._) \                                        *
*    |_(---'-| >   | |       '-'                                        *
*           /_/     \_\                                                 *
*                                                                       *
 ***********************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define pi acos(-1)
typedef  long long ll;
typedef  unsigned long long ull;
typedef  unsigned un;

//defined taking input;
#define sf           scanf
#define si(a)        sf("%d",&a)
#define sc(a)        sf("%c",&a)
#define sii(a,b)     sf("%d %d",&a,&b)
#define siii(a,b,c)  sf("%d %d %d",&a,&b,&c)
#define sl(a)        sf("%lld",&a)
#define sll(a,b)     sf("%lld %lld",&a,&b);
#define slll(a,b,c)  sf("%lld %lld %lld",&a,&b,&c);

#define pf           printf
#define pfi(a)       pf("%d\n",a)
#define pfii(a,b)    pf("%d %d\n",a,b)
#define pfl(a)       pf("%ld\n",a)
#define pfn          pf("\n")
#define pfyes        pf("YES\n")
#define pfno         pf("NO\n")
#define pfYes        pf("Yes\n")
#define pfNo         pf("No\n")

#define wh            while
#define wht(t)        while(t--)

#include<bits/stdc++.h>
using namespace std;
long long f[500005],g[500005];
int main()
{
	string s;
	cin>>s;
	long long l=s.size();
	long long sum=0;
	if(s[0]=='<')  f[0]=1;
	for(int i=1;i<l;++i)
	{
	   if(s[i]=='<'&&s[i-1]=='<') f[i]=f[i-1]+1;
	   else if(s[i]=='<') f[i]=1;
	   else f[i]=0;
    }
    for(int i=l-1;i>=0;--i)
    {
    	if(s[i]=='>'&&s[i+1]=='>') g[i]=g[i+1]+1;
    	else if(s[i]=='>') g[i]=1;
    	else g[i]=0;
	}
	for(int i=0;i<=l;++i)
		sum+=max(f[i-1],g[i]);
	cout<<sum<<endl;
}
