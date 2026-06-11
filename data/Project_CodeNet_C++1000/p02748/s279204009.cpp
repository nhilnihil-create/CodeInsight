#include <bits/stdc++.h>
using namespace std;

int a[100005];
int b[100005];

int main(){
    int A, B, M;
    scanf("%d%d%d", &A, &B, &M);

    int minA = 1012345678;
    for(int i = 0; i < A; i ++){
        scanf("%d", &a[i]);
        minA = min(minA, a[i]);
    }

    int minB = 1012345678;
    for(int i = 0; i < B; i ++){
        scanf("%d", &b[i]);
        minB = min(minB, b[i]);
    }

    int minT = minA + minB;
    for(int i = 0; i < M; i ++){
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        minT = min(minT, a[x-1]+b[y-1]-c);
    }

    printf("%d", minT);
    return 0;
}
