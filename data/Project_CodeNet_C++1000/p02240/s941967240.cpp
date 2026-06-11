#include<iostream>
using namespace std;
#include<stdio.h>

int *P;

int root(int a)
{
    if(P[a] == a) return a;
    P[a] = root(P[a]);
    return P[a]; 
}

void join(int a, int b){ int x = root(a), y = root(b); P[x] = y; }

bool same(int a, int b){ return (root(a) == root(b) ? true : false); }

int main()
{
    int i, n, m, a, b, q;
    scanf("%d %d", &n, &m);
    P = new int [n];
    for(i = 0; i < n; i++) P[i] = i;

    for(i = 0; i < m; i++){ scanf("%d %d", &a, &b); join(a, b); }

    scanf("%d", &q);
    for(i = 0; i < q; i++){
        scanf("%d %d", &a, &b);
        if(same(a, b)){ printf("yes\n"); }else{ printf("no\n"); }
    }
    delete [] P;
    return 0; 
}