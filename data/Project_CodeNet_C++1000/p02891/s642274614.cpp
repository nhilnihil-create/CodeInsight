#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'1')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=500005;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;

string s,ss;

int main()
{
    sync;
    ll k;
    cin>>s>>k;
    ll w=0;
    ll sum=0;
    int n=s.length();
    int f=0;
    for(int i=1;i<n;i++)
        if(s[i]!=s[i-1])
        {
            f=1;
            break;
        }
    ss=s;
    for(int i=1;i<n;i++)
    {
        if(s[i]==s[i-1])
        {
            sum++;
            s[i]='F';
        }
    }
    if(s[n-1]==s[0]&&s[n-1]!='F')
    {
        w++;
    }
    ll zx=sum*k+w*(k-1);
    
    sum=0;
    w=0;
    reverse(ss.begin(),ss.end());
    for(int i=1;i<n;i++)
    {
        if(ss[i]==ss[i-1])
        {
            sum++;
            ss[i]='F';
        }
    }
    if(ss[n-1]==ss[0]&&ss[n-1]!='F')
    {
        w++;
    }
    
    zx=min(zx,sum*k+w*(k-1));
    if(f==0)
    {
        zx=min(zx,1ll*n*k/2);
    }
    cout<<zx<<endl;
    
    return 0;
}
