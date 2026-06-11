#include <cstdio>
#define ll long long

#define mx 200005
int n,k;
ll A[mx];

bool doable(ll target){
    ll tot=0; 
    for(int i=0;i<n;i++){
        tot+=(A[i]%target==0 ? A[i]/target - 1 : A[i]/target);
    }
    return tot<=k;
}

int main(){
    scanf("%d %d",&n,&k);

    for(int i=0;i<n;i++) scanf("%lld",A+i);

    int l=0,r=1e9+5;

    while(r-l>1){
        int mid=(l+r)/2;
        if(doable(mid)) r=mid;
        else l=mid;
    }

    printf("%d\n",r);
}
