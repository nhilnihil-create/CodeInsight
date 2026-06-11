#include <cstdio>

#define ll long long int
#define mx 10000007

ll* num_f;

int main(){
    int N;
    scanf("%d",&N);
    num_f=new ll[N+1];
    for(int i=1;i<=N;i++) num_f[i]=1;

    for(int i=2;i<=N;i++){
        if(num_f[i]==1){
            num_f[i]=2;

            int f=2*i;
            while(f<=N){
                int fc=0;
                int ff=f;
                while(ff%i==0){
                    ff/=i;
                    fc++;
                }
                num_f[f]*=(fc+1);

                f+=i;
            }
        }
    }
    
    ll ans=0;
    for(int i=1;i<=N;i++){
        ans+=(num_f[i]*i);
    }

    printf("%lld\n",ans);
}
