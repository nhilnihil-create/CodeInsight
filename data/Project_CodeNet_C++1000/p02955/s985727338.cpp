#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fo(i,s,e) for( i=s;i<e;i++)
#define rfo(i,s,e) for(i=s;i>e;i--)
#define LLI long long int
#define LI long int 
const LI MOD=1e9+7;
#define pb push_back
#define pob pop_back()
#define sp " "
#define ff first
#define ss second
//            When something is important enough, you do it even if the odds are not in your favor.
LLI n,k;
bool check(LLI x,LLI a[]){
  LLI r[n],i,tot=0,tot1=0;
  fo(i,0,n){
    r[i]=a[i]%x;
  }
  sort(r,r+n);
  fo(i,0,n){
    tot+=x-r[i];
  }
  fo(i,0,n-1){
    tot1+=r[i];
    tot-=x-r[i];
    if(tot==tot1&&tot<=k) return 1;
  }
  return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // code goes here
    int t=1;//cin>>t;
    while(t--){
      cin>>n>>k;
      LLI i,a[n],ans=1;
      LLI sum=0;
      fo(i,0,n){
        cin>>a[i];
        sum+=a[i];
      }
      fo(i,1,sqrt(sum)+1){
        if(sum%i==0){
          if(check(i,a)) ans=max(ans,i);
          if(check(sum/i,a)) ans=max(ans,sum/i);
        }
      }
      cout<<ans;
    }
    return 0;
}