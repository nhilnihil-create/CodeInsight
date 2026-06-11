#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define REP(i,m,n) for(int i=(m);i<(n);++i)
#define rep(i,n) REP(i,0,n)

int main(){
    int N,Q;
    scanf("%d%d",&N,&Q);
    fenwick_tree<long long> fw(N);
    rep(i,N){
        int tmp;
        scanf("%d",&tmp);
        fw.add(i,tmp);
    }
    rep(i,Q){
        int t;
        scanf("%d",&t);
        if(t==0){
            int p,x;
            scanf("%d%d",&p,&x);
            fw.add(p,x);
        }
        else{
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%lld\n",fw.sum(l,r));
        }
    }

    return 0;
}