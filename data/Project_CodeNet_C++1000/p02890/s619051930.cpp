#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,t) for(int i=s;i<t;i++)
#define MAXNUM 333333
int num[MAXNUM];
int main()
{
    int n,a;scanf("%d",&n);
    rep(i,1,n+1)scanf("%d",&a),num[a]++;
    sort(num+1,num+n+1);
    int nowres=n,nownum=n,nowpos=n,x=0;
    rep(i,1,n+1)
    {
        while(nowres*1ll*i>nownum)
        {
            nowres--;
            while(nowpos>0&&num[nowpos]>nowres)x++,nowpos--;
            nownum-=x;
        }
        printf("%d\n",nowres);
    }
}