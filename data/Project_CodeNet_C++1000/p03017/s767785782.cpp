#include<bits/stdc++.h>
#define FRU freopen("out.txt","w",stdout)
#define FRO freopen("in.txt","r",stdin)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mem(ara,n) memset(ara,n,sizeof ara)
#define loop(i,j,n) for(i=j;i<n;i++)
#define rloop(i,j,n) for(i=n;i>=j;i--)
#define INF 2147483647
#define ll long long
#define pii pair<int,int>
#define eps 1e-9
#define mii map<int,int>
#define vi vector<int>
#define all(n) n.begin(),n.end()
#define inf INF
#define INFLL 9223372036854775807
using namespace std;
int main()
{
    int n,m,cnt=0,i,j,k;
    string s="-",s1;
    int a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    cin>>s1;
    s+=s1;
    int ara[200005]={0};
    if(c>d)
    {
        int flag=0,flag1=0;
        for(i=a;i<=c;i++)
        {
            if(s[i]=='#'&& s[i-1]=='#')flag1=1;
        }
        if(s[b-1]=='.')ara[b-1]=1;
        for(i=b;i<=d;i++)
        {
            if(s[i]=='.')ara[i]=ara[i-1]+1;
            if(ara[i]>=3)flag=1;
        }
        if(s[d+1]=='.'&& ara[d]>1)flag=1;
        if(flag&& !flag1)cout<<"Yes\n";
        else cout<<"No\n";
    }
    else
    {
        int flag=0;
        for(i=a;i<=c;i++)
        {
            if(s[i]=='#'&& s[i-1]=='#')flag=1;
        }
        for(i=b;i<=d;i++)
        {
            if(s[i]=='#'&& s[i-1]=='#')flag=1;
        }
        /*if(c>b&& c<d)
        {
            if(s[c-1]=='#'|| s[c+1]=='#')flag=1;
        }*/
        if(!flag)cout<<"Yes\n";
        else cout<<"No\n";
    }

}
