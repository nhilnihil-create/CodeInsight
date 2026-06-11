#include <bits/stdc++.h>
using namespace std;

int main(){
    int k,a,b,kw;
    scanf("%d",&k);
    scanf("%d %d",&a,&b);
    kw=k;
    while(kw<=b){
        if(a<=kw){printf("OK\n");return 0;}
        kw+=k;
    }
    printf("NG\n");
}