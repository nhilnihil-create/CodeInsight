/*
    -ensure correct output format
    -ensure printing required output
    -reread the problem statement
  */

#include<bits/stdc++.h>
using namespace std;
typedef int  ll;
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
const int Max = 3e5 + 2;
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

ll r[Max+5],c[Max+5];

//ll mp[3000000];
ll mp[Max+5];
void soln()
{
    ll i,j,n,m,p,a,sum=0,k,t,b,d,cnt=0,q,l;

      bool flag=false;



      scanf("%d %d %d",&n,&m,&t);




      ll ex=n+m+1;

      set<pll>tt;

      ll mxc=-1,mxr=-1;

      ll ans1=1,ans2=1;
      for(i=0; i<t; i++)
      {
       scanf("%d %d",&a,&b);

         r[a]++;
         c[b]++;

        if(mxr<r[a])
            {
                mxr=r[a];

                ans1=a;
            }

        if(mxc<c[b])
            {
                mxc=c[b];
                ans2=b;
            }



      tt.insert({a,b});


      }

      mxr=ans1;
      mxc=ans2;


      ll mx=0;
      for(i=mxr; i<=mxr; i++)
      {
          for(j=1; j<=m; j++)
          {
              sum=r[i]+c[j];



            if(tt.count({i,j}))sum--;

              mx=max(sum,mx);
          }
      }
        for(i=1; i<=n; i++)
      {
          j=mxc;

              sum=r[i]+c[j];



            if(tt.count({i,j}))sum--;

              mx=max(sum,mx);

      }
 printf("%d\n",mx);


}
int main()
{

   fastread();

   soln();
}

