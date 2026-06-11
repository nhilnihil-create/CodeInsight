#include <stdio.h>
#include <atcoder/dsu>


using namespace std;
using namespace atcoder;


int main(void){
    int n, q;
    int *t, *u, *v;

    scanf("%d", &n);
    scanf("%d", &q);

    dsu d(n);


    t = (int *)malloc(sizeof(int) * q);
    u = (int *)malloc(sizeof(int) * q);
    v = (int *)malloc(sizeof(int) * q);

    for(int i = 0; i < q; i++){
        scanf("%d", t + i);
        scanf("%d", u + i);
        scanf("%d", v + i);
    }

    for(int i = 0; i < q; i++){
        if(t[i] == 0)
            d.merge(u[i], v[i]);
        else{
            if(d.same(u[i], v[i]))
                printf("1\n");
            else
                printf("0\n");
        }
    }

    free(t);
    free(u);
    free(v);

    return 0;
}