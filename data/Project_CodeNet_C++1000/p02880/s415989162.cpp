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
signed main()
{
    fastio();
   int n,c=0,z=0,zz=0;
   cin>>n;
   for(int i=1;i<=9;i++)
   {
       for(int j=1;j<=9;j++)
       {
           if(i*j==n)
           {
           c++;
           break;
           }
       }
   }
   if(c)
   cout<<"Yes";
   else
   cout<<"No";
   
}
