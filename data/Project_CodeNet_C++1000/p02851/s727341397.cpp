#include <iostream>
#include<algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include<map>
#include<set>
#include<sstream>
#define INF 0x3f3f3f3f
#define DOF 0x7f7f7f7f
#define mem(a,b) memset(a,b,sizeof(a))
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
const int maxn=2e5+10;
ll a[maxn],sum[maxn];
map<unsigned int,ll>num;
ll ans;
int main()
{
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=0;i<=n;++i){
        if(i>=k){
            num[((sum[i-k]-(i-k))%k)]--;
        }
        if(num[(sum[i]-i)%k]){
            ans+=num[(sum[i]-i)%k];
        }
        num[(sum[i]-i)%k]++;
    }
    cout<<ans<<endl;
    return 0;
}
