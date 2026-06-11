#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
const int SIZEN = 5010;
LL d[SIZEN];
LL t[SIZEN];
int K,Q;

int num0[SIZEN];
int main(){
    scanf("%d%d",&K,&Q);
    for(int i = 1;i <= K;i++)scanf("%d",&d[i]);
    for(int i = 1;i <= Q;i++){
        LL n,x,m;
        scanf("%lld%lld%lld",&n,&x,&m);
        x %= m;
        for(int j = 1;j <= K;j++){
            t[j] = d[j] % m;
            if(t[j] == 0)num0[j] = 1;
            else num0[j] = 0;
            num0[j] += num0[j-1];
        }
        for(int j = 1;j <= K;j++)t[j] += t[j-1];
        LL num = (n-1) / K;
        
        int rest = (n-1) % K; 
        LL num00 = num0[K] * num + num0[rest];

        LL a = x + num * t[K] + t[rest];

        printf("%lld\n",n-1 - a / m - num00);
    }
    return 0;
}