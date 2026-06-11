#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int main(void){
    int N, D;
    
    scanf("%d%d", &N, &D);
    printf("%d", (N + 2 * D) / (2 * D + 1));

    return 0;
}