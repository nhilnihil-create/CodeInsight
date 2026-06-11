#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define shalaby ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);cerr.tie(0);
#define mod 100000000
using namespace std;

inline int D()
{
    int t;
    scanf("%d",&t);
    return t;
}
inline ll llD()
{
    ll t;
    scanf("%lld",&t);
    return t;
}
 ll Max=1e18+8;
const int OO=-1e6;
int xt[4]= {1,0,0,-1};
int yt[4]= {0,1,-1,0};
////////////////////////////////////////////////////////////////////////////////////

ll mem[100005][3],a[105],b[105],n,m,k;
bool valid(int x,int y)
{
    return x>-1 && y>-1 && x<n && y<m;
}
void init()
{
    memset(mem,-1,sizeof mem);
}

/////////////////////////////////////////////////////////////////////




int main()
{
    init();
    int T=1;
///   T=D();
    while(T-->0)
    {
        string st1,st2;
        cin >> st1>>st2;
        int a=st1.size();
        int b=st2.size();
        int c=a-b;
        int ans=1009,cnt=0;
        if(c<0)
            return puts("0"),0;
        for(int i=0;i<=c;i++)
        {

            for(int j=0;j<b;j++)
            {
            if(st1[i+j]!=st2[j])
                cnt++;
              ///  cout<<st1[i+j]<<" : "<<st2[i+j]<< " ";
             }
           ///  cout<<endl;
             ans=min(ans,cnt);
             cnt=0;

        }
        cout<<ans;


    }
}
