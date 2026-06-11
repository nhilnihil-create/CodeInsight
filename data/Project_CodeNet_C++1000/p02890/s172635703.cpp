#include<bits/stdc++.h>
#define int long long int
#define ull unsigned long long int
#define getFaster ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define rep(i,init,n) for(int i=init;i<n;i++)
#define rev(i,n,init) for(int i=n;i>=init;i--)
#define MAXN 1200005
#define MOD 1000000007
#define f first
#define s second
#define endl '\n'
#define pii pair<int,int>
#define precise cout<<fixed<<setprecision(6)
using namespace std;
const double PI = atan(1.0)*4;
const int64_t INF=100000000000000003;
const int32_t LOG=21;
const int BIG=pow(2,20);
int32_t main(){
        // getFaster;
         int n;
         cin>>n;
         vector<int> v;
         int arr[n+1];
         int cnt[n+1];
         int bounds[n+1];
         int pref[n+1];
         fill(cnt,cnt+n+1,0);
         v.clear();
         rep(i,1,n+1)
         {
           cin>>arr[i];
           cnt[arr[i]]++;
         }
         rep(i,1,n+1)
         {
           if(cnt[i]!=0)v.push_back(cnt[i]);
         }
         int tot=(int)(v.size());
         sort(v.begin(),v.end());
         rep(x,1,n+1)
         {
               int l=0,r=tot-1;
               int ans=tot;
               while(l<=r)
               {
                  int mid=(l+r)>>1;
                  if(v[mid]<x)
                  {
                     l=mid+1;
                  }
                  else
                  {
                     ans=min(ans,mid);
                     r=mid-1;
                  }  
               }
               bounds[x]=ans-1;
         }
         pref[0]=v[0];
         rep(i,1,v.size())pref[i]=pref[i-1]+v[i];
         rep(k,1,n+1)
         {
             int l=1,r=n/k;
             int ans=0;
             while(l<=r)
             {
                int mid=(l+r)>>1;
                int cur=bounds[mid];
                int val=tot-cur-1;
                if(cur!=-1)val+=(pref[cur]/mid);
                if(val>=k){ans=max(ans,mid);l=mid+1;}
                else r=mid-1;
             }
             cout<<ans<<endl; 
         }
         return 0;
}