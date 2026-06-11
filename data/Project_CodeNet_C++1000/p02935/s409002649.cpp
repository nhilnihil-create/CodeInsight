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

#define pi acos(-1)
typedef  long long ll;
typedef  unsigned long long ull;
typedef  unsigned un;
#define  vi  vector<int>
#define  vl  vector<ll>
#define  vd  vector<double>


//defined taking input;
#define sf           scanf
#define si(a)        sf("%d",&a)
#define sc(a)        sf("%c",&a)
#define sii(a,b)     sf("%d %d",&a,&b)
#define siii(a,b,c)  sf("%d %d %d",&a,&b,&c)
#define sl(a)        sf("%lld",&a)
#define sll(a,b)     sf("%lld %lld",&a,&b)
#define slll(a,b,c)  sf("%lld %lld %lld",&a,&b,&c)

#define pf           printf
#define pfi(a)       pf("%d\n",a)
#define pfii(a,b)    pf("%d %d\n",a,b)
#define pfl(a)       pf("%ld\n",a)
#define pfn          pf("\n")
#define pfyes        pf("YES\n")
#define pfno         pf("NO\n")
#define pfYes        pf("Yes\n")
#define pfNo         pf("No\n")
#define wh           while
#define wht(t)       while(t--)
#define endl         "\n"
#define pb           push_back

//defined using loop
#define For(i,a,n)   for(int i=a;i<n;i++)

#define input        freopen("input.txt","r",stdin);
#define output       freopen("output.txt","w",stdout);

using namespace std;

int main()
{

    int n;
    cin>>n;
    vd a(n);
    For(i,0,n){
        cin>>a.at(i);
    }
    sort(a.begin(),a.end());
    double f = a.at(0);
    For(i,1,n){
        f=(f+a.at(i))/2;
    }
    cout<<fixed<<setprecision(15)<<f<<endl;


    return 0;
}
