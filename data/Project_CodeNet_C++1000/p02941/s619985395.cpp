#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<ctime>
#include<vector>
#include<set>
#include<map>
#include<stack>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define int long long
priority_queue<pair<int,int> >q;
int n,m,b[200100],a[200100],pre[200100],nxt[200100];
signed main(){
    int i,j,k,ans=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(i=1;i<=n;i++){
      scanf("%lld",&b[i]);
      q.push(mp(b[i],i));
    }
    for(i=1;i<=n;i++){
      nxt[i]=i+1;
      pre[i]=i-1;
    }
    pre[1]=n;
    nxt[n]=1;
    while(!q.empty()){
      int x=q.top().se;
      q.pop();
      if(b[x]==a[x])continue;
      int y=pre[x],z=nxt[x];
      if(b[x]-b[y]-b[z]<a[x]){
          puts("-1");
          return 0;
      }
      k=b[x]-a[x];
      ans+=k/(b[y]+b[z]);
      b[x]=(k%(b[y]+b[z]))+a[x];
      if(a[x]!=b[x])q.push(mp(b[x],x));
    }
    cout<<ans<<"\n";
    return 0;
}