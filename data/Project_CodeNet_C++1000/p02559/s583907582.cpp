#include <iostream>
using namespace std;
long long N, Q;
long long trees[500005] = {0};

void update(int idx, long long value){
    idx = idx + 1;
    while( idx<=N+1 ){
        trees[idx]+= value;
        idx += idx&(-idx);
    }
}

long long getSum(int idx){
    idx = idx + 1;
    long long  s= 0;
    while(idx > 0){
        s += trees[idx];
        idx -= idx&(-idx);
    }

    return s;
}

int main(){
    scanf("%lld%lld",&N,&Q);
    for(int i = 1; i <= N; ++i){
        long long a;
        scanf("%lld",&a);
        update(i,a);
    }

    for(int i = 0 ; i < Q; ++i){
        long long x1,x2,x3;
        scanf("%lld%lld%lld",&x1,&x2,&x3);
        if (x1 == 0){
            update(x2+1,x3);
        }else{
            printf("%lld\n",getSum(x3)-getSum(x2));
        }
    }
}