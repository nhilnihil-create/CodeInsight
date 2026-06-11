#include <cstdio>
#include <vector>
using namespace std;
#define ll long long

#define mx 200005

int main(){
    int N;
    scanf("%d", &N);

    ll ans=(ll)N*(N+1)*(N+2);
    ans/=6;

    for(int i=0;i<N-1;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        if(x>y) swap(x,y);
        ans-=(ll)x*(N+1-y);
    }

    printf("%lld\n",ans);
}
