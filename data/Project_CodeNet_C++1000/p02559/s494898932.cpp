#include <iostream>
using namespace std;

typedef long long LL;
#define MAXN 500005
LL ft[MAXN];
int n, q;

//fenwick tree
void add(int i, LL val){
    for(; i<MAXN; i+=i&-i){
        ft[i] += val;
    }
}

LL sum(int i){
    LL ret=0;
    for(; i>0; i-=i&-i){
        ret += ft[i];
    }
    return ret;
}

LL range_sum(int fr, int to){
    return sum(to) - sum(fr-1);
}
//fenwick tree

int main() {
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        LL a;
        cin>>a;
        add(i,a);
    }
    
    while(q--){
        int op,u,v;
        cin>>op>>u>>v;
        u++;
        if(op==0) add(u, v);
        else{
            printf("%lld\n", range_sum(u, v));
        }
    }
    return 0;
}
