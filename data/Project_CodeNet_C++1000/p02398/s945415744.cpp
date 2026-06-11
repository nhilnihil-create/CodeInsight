#include<cstdio>

int main() {
    int a,b,c,x,k;
    k =0;
    scanf ("%d %d %d",&a,&b,&c);
    for (int x = a;x <= b;x++){
        if (c % x == 0){
            k = k + 1;
        }
    }
    printf("%d\n",k);
}

