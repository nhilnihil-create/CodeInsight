#include <bits/stdc++.h>
using namespace std;

int n;
int A[1000000];
int cnt = 0;
int m;
int G[100];

void inssort(int g) {
    for(int i=g; i<n; i++) {
        int v = A[i];
        int j = i - g;
        while(j >= 0 && A[j] > v) {
            A[j+g] = A[j];
            j -= g;
            cnt++;
        }
        A[j+g] = v;
    }
}

void shesort() {
    for(int i=m-1; i>=0; i--){
        inssort(G[i]);
    }
}

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &A[i]);
    }

    m = 0;
    for(int h=1; h<=n; m++, h=3*h+1) {
        G[m] = h;
    }

    shesort();

    printf("%d\n", m);
    for(int i=m-1; i>=0; i--){
        printf("%d%c", G[i], i ? ' ' : '\n');
    }
    printf("%d\n", cnt);
    for(int i=0; i<n; i++){
        printf("%d\n", A[i]);
    }
}