/*
    -ensure correct output format
    -ensure printing required output
    -reread the problem statement
  */

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll>pll;
typedef pair<ll,pair<ll,ll>>plll;
#define fastread() (ios_base:: sync_with_stdio(false),cin.tie(NULL));
#define vll(v) v.begin(),v.end()
#define all(x) x.rbegin(),x.rend()
#define min3(a, b, c)   min(a, min(b, c))
#define max3(a, b, c)   max(a, max(b, c))
#define F first
#define S second
#define in  freopen("input.txt", "r", stdin)
#define out  freopen("output.txt", "w", stdout)
#define minheap int,vector<int>,greater<int>
#define pb push_back
#define eb emplace_back
#define ischar(x)  (('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z'))
#define isvowel(ch) ((ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')||(ch=='A'|| ch=='E' || ch=='I'|| ch=='O'|| ch=='U'))
#define bug cout<<"BUG"<<endl;
const int Max = 2e3+ 2;
const int Mod = 1e9 + 7;
const double PI  =3.141592653589793238463;
bool compare(const pair<ll,ll> &a, const pair<ll,ll> &b)
{
    return (a.first > b.first);
}
ll lcm(ll a,ll b)
{
    if(a==0 || b==0)return 0;

    return a/__gcd(a,b)*b;
}

void input(ll ara[],ll n)
{
    for(ll i=0; i<n; i++)cin>>ara[i];
}
void print(ll ara[],ll n)
{
    for(ll i=0; i<n; i++)
        cout<<ara[i]<<" ";
    cout<<endl;
}


ll up[Max][Max],down[Max][Max],Left[Max][Max]
,Right[Max][Max];

ll n,m;

char ara[Max][Max];





void cum()
{

    ll i,j;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(ara[i][j]=='#')
                Left[i][j]=0;

            else Left[i][j]=Left[i][j-1]+1;
        }
    }

    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(ara[j][i]=='#')
                up[j][i]=0;

            else up[j][i]=up[j-1][i]+1;
        }
    }

    for(j=m; j>=1; j--)
    {
        for(i=n; i>=1; i--)
        {
            if(ara[i][j]=='#')
                down[i][j]=0;

            else down[i][j]=down[i+1][j]+1;
        }
    }
    for(i=n; i>=1; i--)
    {
        for(j=m; j>=1; j--)
        {
            if(ara[i][j]=='#')
                Right[i][j]=0;

            else Right[i][j]=Right[i][j+1]+1;
        }
    }

}

int main()
{

    fastread();

    ll i,j,p,a,sum=0,k,t,b,c,d,cnt=0,q,l,r,ans=0;

    bool flag=false;



    cin>>n>>m;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
            cin>>ara[i][j];
    }

    cum();

    ans=0;


     for(i=1; i<=n; i++)
     {
         for(j=1; j<=m; j++)
         {
             if(ara[i][j]!='#')
             {
            ans=max(ans,up[i][j]+down[i][j]+Left[i][j]+Right[i][j]-3);
             }

         }
     }

     cout<<ans<<endl;












}

