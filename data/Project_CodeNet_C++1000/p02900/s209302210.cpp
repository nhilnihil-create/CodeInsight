#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
ll fac[32];
int tot;//质因子
bool prime[1000006];
ll p[1000006],cnt;

void initprim(){
	int i,j;
    cnt = 0;
    memset(prime,true,sizeof(prime));
    for(i=2; i<1000006; i++)
    {
        if(prime[i])
        {
            p[cnt++] =(ll)i;
            for(j=i+i; j<1000006; j+=i)
                prime[j] = false;
        }
    }
}

bool check(ll x){
    int i;
    for(i=0;i<tot;i++){
        if(x==fac[i]) return true;
    }
    return false;
}

int main(){
	ll a,b;
	int i;
	int ans=1;
	initprim();
	scanf("%lld%lld",&a,&b);
        for(i=0,tot=0;i<cnt&&p[i]*p[i]<=a;i++){
            if(a%p[i]==0){
                while(a%p[i]==0){
                    a=a/p[i];
                }
                fac[tot++]=p[i];
            }
        }
        if(a>1){
            fac[tot++]=a;
        }

        for(i=0;i<cnt&&p[i]*p[i]<=b;i++){
            if(b%p[i]==0){
                while(b%p[i]==0){
                    b=b/p[i];
                }
                if(check(p[i])) ans++;
            }
        }
        if(b>1){
            if(check(b)) ans++;
        }
        printf("%d\n",ans);
        return 0;
}
