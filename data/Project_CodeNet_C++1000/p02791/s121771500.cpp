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
   int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int mx=a[0], ans=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]<=mx)
        {
            ans++;
            mx=min(mx,a[i]);
        }
    }
    cout<<ans;
}
    
