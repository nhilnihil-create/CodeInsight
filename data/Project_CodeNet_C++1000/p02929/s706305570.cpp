#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
int a[200005];//1为左括号，2为右括号
char s[200005];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s+1);
    int t=0;
    if(s[1]=='W'||s[2*n]=='W')
    {
        printf("0\n");
        return 0;
    }
    for(int i=1;i<=2*n;i++)
    {
        if(s[i]=='B')
        {
            if(t%2==0)
            {
                a[i]=1;
                t++;
            }
            else
            {
                a[i]=0;
                t--;
            }
        }
        else if(s[i]=='W')
        {
            if(t%2==0)
            {
                a[i]=0;
                t--;
            }
            else a[i]=1,t++;
        }
    }
    if(t!=0)
    {
        printf("0\n");
        return 0;
    }
    t=0;
    ll ans=1;
    for(int i=1;i<=2*n;i++)
    {
        if(a[i]==1)
        {
            t++;
        }
        else
        {
            ans=(ans*t)%mod;
            t--;
        }
    }
    if(t!=0)
    {
        printf("0\n");
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        ans=ans*i%mod;
    }
    printf("%lld\n",ans);
}

/*----------------------------------

                     //
         \\         //
          \\       //
    ##DDDDDDDDDDDDDDDDDDDDDD##
    ## DDDDDDDDDDDDDDDDDDDD ##   ________   ___   ___        ___   ________   ___   ___        ___
    ## hh                hh ##   |\   __  \ |\  \ |\  \      |\  \ |\   __  \ |\  \ |\  \      |\  \
    ## hh    //    \\    hh ##   \ \  \|\ /_\ \  \\ \  \     \ \  \\ \  \|\ /_\ \  \\ \  \     \ \  \
    ## hh   //      \\   hh ##    \ \   __  \\ \  \\ \  \     \ \  \\ \   __  \\ \  \\ \  \     \ \  \
    ## hh                hh ##     \ \  \|\  \\ \  \\ \  \____ \ \  \\ \  \|\  \\ \  \\ \  \____ \ \  \
    ## hh      wwww      hh ##      \ \_______\\ \__\\ \_______\\ \__\\ \_______\\ \__\\ \_______\\ \__\
    ## hh                hh ##       \|_______| \|__| \|_______| \|__| \|_______| \|__| \|_______| \|__|
    ## MMMMMMMMMMMMMMMMMMMM ##
    ##MMMMMMMMMMMMMMMMMMMMMM##                             Release 2.6.1. Powered by jinkela-core 2.4.12.
         \/            \/
*/
