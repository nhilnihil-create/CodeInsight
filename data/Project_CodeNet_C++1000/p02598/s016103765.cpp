#include<bits/stdc++.h>

using namespace std;

#define int long long

int n,k;
vector<int>v(200005);

bool calc(int x)
{
    int cnt=0;
    for(int i=0;i<n;i++){
        if(v[i]%x==0)cnt+=(v[i]/x)-1;
        else cnt+=(v[i]/x);
    }
    return cnt<=k;
}

int32_t main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>v[i];
   }
   int lo=1,hi=*max_element(v.begin(),v.begin()+n),ans;
   while(lo<=hi){
      int mid=(lo+hi)/2;
      if(calc(mid))hi=mid-1,ans=mid;
      else lo=mid+1;
   }
   cout<<ans<<endl;
}
