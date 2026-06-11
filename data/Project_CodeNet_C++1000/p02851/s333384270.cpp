#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
const int SIZEN = 200010;
map<LL,int> mp;
int N,K;
LL sum[SIZEN] = {0};
int main(){
    scanf("%d%d",&N,&K);
    for(int i = 1;i <= N;i++){
        scanf("%lld",&sum[i]);
        sum[i] += sum[i-1];
    }
    LL ans = 0;
    mp[0] = 1;
    int now = 0;
    for(int i = 1;i <= N;i++){
        if(i >= K)mp[sum[now++]]--;
        sum[i] -= i;
        sum[i] = (sum[i] % K + K) % K;
        ans += mp[sum[i]];
        mp[sum[i]]++;
    }
    printf("%lld\n",ans);
    return 0;
}