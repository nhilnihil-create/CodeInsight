#include<bits/stdc++.h>
#pragma GCC optimize("Ofast","no-stack-protector","unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F(i,L,R) for(int i=L;i<R;++i)
#define FE(i,L,R) for(int i=L;i<=R;++i)
#define getI(a) scanf("%d", &a)
#define getII(a,b) scanf("%d%d", &a, &b)
#define getIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define VgetI(n) int (n); scanf("%d",&(n))
#define VgetII(n,m) int (n),(m); scanf("%d %d",&(n),&(m))
#define VgetIII(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k))
#define debug(x) cout<<(#x)<<"="<<x<<"\n";
#define qq cout<<"QQ\n";
#define pb emplace_back
#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second
#define ll long long
#define INF 2000000000
ll preSum[200005];
map<int,int> m;
int main(){
        int n,k;
        while(~getII(n,k)){
                m.clear();
                preSum[0]=0;
                FE(i,1,n){
                        VgetI(x);
                        x--;
                        preSum[i]=(preSum[i-1]+x+k)%k;
                }
                ll ans=0;
                FE(i,0,n){//tail
                        if(i-k>=0) m[preSum[i-k]]--;
                        ans+=m[preSum[i]];
                        m[preSum[i]]++;
                }
                printf("%lld\n",ans);
        }
}
