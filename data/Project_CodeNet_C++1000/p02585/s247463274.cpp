// Create by JJL
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;

const int N=5010,Mod=1e9+7;
int a[N],p[N],len[N];
bool st[N];
LL sum[N][N],tsum[N][N];
int main(){
    IOS;
    /* START CODE */
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;++i) cin>>p[i];
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i){
       memset(st,0,sizeof st);
       int pos=i,idx=0;
       LL res=0;
       while(st[pos]==0){
            sum[i][++idx]=res+a[pos];
            res+=a[pos];
            st[pos]=1;
            pos=p[pos];
       }
       len[i]=idx;
    }
    LL ans=-1e18;
    memset(tsum,-0x3f,sizeof tsum);
    for(int i=i;i<=n;++i){
        for(int j=1;j<=len[i];++j){
            tsum[i][j]=max(tsum[i][j-1],sum[i][j]);
        }
    }
    for(int i=1;i<=n;++i){
        LL res=k/len[i]*sum[i][len[i]]+tsum[i][k%len[i]];//走最多圈
        res=max(tsum[i][min(k,len[i])],res);//走最少圈
        if(k>=len[i]){
            res=max(tsum[i][len[i]],res);
            res=max((k/len[i]-1)*sum[i][len[i]]+tsum[i][len[i]],res);
        }
        ans=max(ans,res);
    }
    cout<<ans<<endl;
    return 0;
}
