#include<bits/stdc++.h> 
#define int long long 
#define pp pair<int,int> 
#define ss second 
#define ff first 
#define pb push_back
#define mod 1000000007
#define mk(arr,n,type)  type *arr=new type[n];
#define sl s1.length();
using namespace std; 
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
int p(int n)
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
   int n,c=0,a;
   cin>>n;
   int x=sqrt(n);
    if(p(n)==1)
   cout<<n-1;
   else
   {
   for(int i=x;i>=1;i--)
   {
       if(n%i==0)
       {
           a=i;
           break;
       }
   }
   int zz=n/a;
   cout<<(a+zz)-2;
   }
}