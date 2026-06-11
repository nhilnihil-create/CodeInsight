#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);  
  cout.tie(0);   

  #ifndef ONLINE_JUDGE
      if(fopen("INPUT.txt","r"))
      {
      freopen ("INPUT.txt" , "r" , stdin);
      freopen ("OUTPUT.txt" , "w" , stdout);
      }
  #endif  

  int n,m,v,p;
  cin>>n>>m>>v>>p;
  int a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  sort(a,a+n,greater<>());
  int l=0,r=n-1;
  int mx=-1;
  while (l<=r)
  {
    int mid=l+(r-l)/2;
    int z=mid+1-p;
    if(z<=0)
    {
      l=mid+1;
      mx=max(mx,mid);
    }
    else
    {
      vector<int>temp;
      int fi=a[mid]+m;
      for(int i=p-1;i<n;i++)
      {
        if(i!=mid)
          temp.push_back(a[i]);
      }
      reverse(temp.begin(),temp.end());
      int x=(v-p)*m;
      x=max(x,0LL);
      bool flag=true;
      for(auto i:temp)
      {
        int y=fi-i;
        if(y<0)
          flag=false;
        x-=min(x,min(m,y));
      }
      if(x>0)
        flag=false;
      if(flag)
      {
        mx=max(mx,mid);
        l=mid+1;
      }
      else
      {
        r=mid-1;
      }      
    }    
  }

  cout<<mx+1;

}