#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        if(i*108/100 == n){
            printf("%d\n", i);
            return 0;
        }
    }
    printf(":(\n");
}