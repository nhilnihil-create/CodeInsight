#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool flag[1000002];

int main()
{
    int n,a,cnt;
    ll i,j;
    bool mark=false;
    scanf("%d",&n);
    cnt=-1;
    for(i=1; i<=n; i++)
    {
        scanf("%d",&a);
        if(cnt==-1)cnt=a;
        flag[a]=true;
        cnt=__gcd(cnt,a);
    }
    if(cnt>1)printf("not coprime\n"),exit(0);
    cnt=0;
    for(i=2; i<1000001; i++)
    {
        a=0;
        for(j=1; i*j<1000001; j++)a+=flag[i*j];
        if(a>1)mark=true;
        cnt=max(cnt,a);
    }
    if(!mark)printf("pairwise coprime\n");
    else if(cnt<n)printf("setwise coprime\n");
    else printf("not coprime\n");
    return 0;
}
