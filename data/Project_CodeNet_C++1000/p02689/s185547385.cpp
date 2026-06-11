/// prime factorization when number is big
#include <bits/stdc++.h>
using namespace std;
#define Mx 200001
typedef long long L;
L High[Mx],A[Mx],n,m,u,v;
void solve(){
    L c=0;
    for(L i=1;i<=n;i++){
        if(High[i]>A[i]){
            c++;
        }
    }
    printf("%lld\n",c );
}
int main()
{
    scanf("%lld%lld",&n,&m);
    for(L i=1;i<=n;i++)scanf("%lld",&High[i]);
    for(L i=0;i<m;i++){
        scanf("%lld%lld",&u,&v);
        A[u]=max(A[u],High[v]);
        A[v]=max(A[v],High[u]);
    }
    solve();
    return 0;
}
/// empty() lld I64d push_back() top() pop() insert() upper_bound() lower_bound() memset() max() min() scanf continue
