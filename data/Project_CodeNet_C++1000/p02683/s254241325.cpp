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



ll cost[15];

ll n,m,x;

ll v[15][15];

ll All[15];

ll mx=1e18;

ll ans;

void sum(ll pos)
{
    for(ll i=0; i<m; i++)
        All[i]+=v[pos][i];

    ans+=cost[pos];
}

void check()
{
    for(ll i=0; i<m; i++)
        if(All[i]<x)return ;

    mx=min(mx,ans);


}
void allPossibleSubset(ll arr[], ll n)
{
    ll count = pow(2ll, n);

    ll a;

    for (int i = 0; i < count; i++) {

        for (int j = 0; j < n; j++) {

            if ((i & (1 << j)) != 0)
                {

                    sum(arr[j]);
                }
        }

        check();
       fill(All,All+n+1,0);
        ans=0;
        //cout << "\n";
    }
}

int main()
{

   fastread();

   ll i,j,p,a,sum=0,k,t,b,c,d,cnt=0,q,l,r;

      bool flag=false;

      string str;

      cin>>n>>m>>x;

      for(i=0; i<n; i++)
      {
          cin>>cost[i];

          for(j=0; j<m; j++)
          {
              cin>>v[i][j];
          }
      }

      ll ara[n+2];

      for(i=0; i<n; i++)
      {
          ara[i]=i;
      }

      allPossibleSubset(ara,n);

      if(mx==1e18)mx=-1;
      cout<<mx<<endl;



}

