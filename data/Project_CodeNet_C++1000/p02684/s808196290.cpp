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
const int Max = 2e6 + 10;
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



vector<ll>adj[Max+10];

ll dis[Max+10];

ll vis[Max+10];

ll ans=-1;

ll cycle=-1;

 bool flag=false;

 ll k;

void dfs(ll s,ll p)
{
    if(flag)return ;

    if(vis[s])
    {
        cycle=s;

        flag=true;
        return ;
    }


    dis[s]=dis[p]+1;

    if(k==dis[s] && flag==false)
    {
        ans=s;

        flag=true;

        return ;
    }

    vis[s]=true;


    for(auto x : adj[s])
    {
        dfs(x,s);
    }


}
int main()
{

   fastread();

   ll i,j,n,m,p,a,sum=0,b,c,d,cnt=0,q,l,r;



         cin>>n>>k;

         ll ara[n+1];

         for(i=1; i<=n; i++)
         {
             cin>>a;

             ara[i]=a;


             adj[i].eb(a);
         }



         dis[0]=-1;
          dfs(1,0);

        //  cout<<cycle<<endl;

          if(~ans)cout<<ans<<endl;

          else
          {
              vector<ll>v;
              v.eb(cycle);

              ans=cycle;

              while(ara[cycle]!=ans)
              {
                  cycle=ara[cycle];



                  v.eb(cycle);
              }

            k-=dis[ans];

            k%=v.size();

            cout<<v[k]<<endl;


          }





}

