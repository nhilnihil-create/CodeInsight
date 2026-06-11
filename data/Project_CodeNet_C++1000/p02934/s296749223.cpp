#include <bits/stdc++.h>
using namespace std;

int main(){

    float n, t;
    float din = 0;
    scanf("%f", &n);
    for(int i = 0; i < n; i++){
        scanf("%f", &t);
        din += 1 / t;
    }
    printf("%.9f", 1 / din);

    return 0;
}
