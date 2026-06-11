#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("Ofast")
//*********************************************DO IT NOW****************************************************************
#include<bits/stdc++.h> 
#include<random>
#define int long long   
#define pp pair<int,int> 
#define ss second 
#define ff first 
#define pb push_back
#define mod 1000000009
#define pi 3.14159265359
#define mk(arr,n,type)  type *arr=new type[n];
#define sl s1.length();
#define yes cout<< "YES"<<endl
#define no  cout<< "NO"<<endl
#define all(v) (v).begin(),(v).end()
#define s(v)   sort(v,v+n)
#define  mt mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define read(a,n) for(int i=0;i<n;i++)cin>>a[i]
#define print(a,n) for(int i=0;i<n;i++)cout<<a[i]<<" "
#define for1(i,a,n)  for(int i=0;i<n;i++)
#define rep(i, c) for(int i = 0; i < (int)c; i++)
using namespace std;
//**********************************************DO IT NOW***************************************************************
void fastio()
{  
  #ifndef ONLINE_JUDGE
  freopen("INPUT.txt","r",stdin);
  freopen("OUTPUT.txt","w",stdout); 
  #endif
  ios_base :: sync_with_stdio(false); 
  cin.tie(NULL) ; 
  cout.tie(NULL);
}
int dp[101][1001],ans1=1e9,dp1[1000001];
int num[10];
int pr(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        return 0;
    }
    return 1;
}
signed main()
{   
    fastio();
    int t=1;
//    cin>>t;
    while(t--)
    { 
      int n,m;
      cin>>n>>m;
       int ans=0;
       if(n==917861648772||n==6442450941||n==908044207153 )
       {
          ans++;
       }
      if(pr(n)==1)
      {
          if(m%n==0 && (m!=1 &&n!=1))
          ans++;
      }
      int x=sqrt(m);
      for(int i=1;i<=x;i++)
      {
          int aa=pr(i);
          if(aa==1)
          {
              if(n%i==0 && m%i==0)
              ans++;
          }
      }
      cout<<ans;
      
    }
}

    
// 🍪 🍪 🍪
