#include<set>
#include<cmath>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<numeric>
#include<vector>
#include<ctime>
#include<queue>
#include<list>
#include<map>
#define pi acos(-1)
#define INF 0x7fffffff
#define clr(x)  memset(x,0,sizeof(x));
#define clrto(x,siz,y)  for(int xx=0;xx<=siz;xx++)  x[xx]=y;
#define clrset(x,siz)  for(int xx=0;xx<=siz;xx++)  x[xx]=xx;
#define clrvec(x,siz) for(int xx=0;x<=siz;xx++)  x[xx].clear();
#define fop   freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
#define myprogram By_135678942570
#define clrcpy(x,siz,y)  for(int xx=0;xx<siz;xx++)  x[xx]=y[xx];
using namespace std;
map<string,int>mp;
main()
{
     string tt;
     string maxstr=" ";
     string maxstr2=" ";
     int maxn=0;
     while(cin>>tt)
     {
         mp[tt]++;
         if(mp[tt]>mp[maxstr])
            maxstr=tt;
         if(tt.size()>maxn)
            maxn=tt.size(),maxstr2=tt;
     }
     cout<<maxstr<<" "<<maxstr2<<endl;
     return 0;
}