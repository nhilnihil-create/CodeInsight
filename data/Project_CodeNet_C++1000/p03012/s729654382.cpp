#include<bits/stdc++.h> 
#include<random>
#define int long long   
#define pp pair<int,int> 
#define ss second 
#define ff first 
#define pb push_back
#define mod 1000000007
#define mk(arr,n,type)  type *arr=new type[n];
#define sl s1.length();
#define yes cout<< "Yes"<<endl
#define no  cout<< "No"<<endl
#define all(v) (v).begin(),(v).end()
#define  mt mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
    int t=1;
   // cin>>t;
    while(t--)
    {    
       int n,x=0,s=1000000,sum=0;
       cin>>n;
      int a[n];
      for(int i=0;i<n;i++)
      {
      cin>>a[i];
      sum+=a[i];
      }
      for(int i=0;i<n-1;i++)
      {   
          x+=a[i];
          s=min(s,abs(x-abs(sum-x)));
      }
      cout<<s;
       
    }
}
// 🍪 🍪 🍪