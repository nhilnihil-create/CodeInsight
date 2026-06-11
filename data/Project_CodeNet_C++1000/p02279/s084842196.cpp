#include<iostream>
using namespace std;
#include<stdlib.h>    // use "exit" function.
#include<stdio.h>

int main()
{
    int i, n, d, p, q;  // n:how many node.
    scanf("%d", &n);
    int *P, *C, *S;  // P:parent, C:children, S:sibling.
    P = new int [n]; C = new int [n]; S = new int [n];
    if(P == NULL || C == NULL || S == NULL) exit(EXIT_FAILURE);

    for(i = 0; i < n; i++){ P[i] = -1; S[i] = -1; }  // initialize for -1.

    while(cin >> i){
        scanf("%d", &d);   // d:how many child.
        if(d == 0){     // if nobody ??? -1.
            C[i] = -1;
        }else{
            scanf("%d", &p);  // p is the first.
            C[i] = p; P[p] = i;
            while(d > 0){
                if(d == 1){ break; }
                else{ 
                    scanf("%d", &q);  // q is sibling of p.
                    S[p] = q; P[q] = i;  // i is parent of q.
                    p = q; d--;
                }
            };
        }
    };

    for(i = 0; i < n; i++){
        printf("node %d: parent = %d, depth = ", i, P[i]);
        p = P[i]; d = 0;
        while(p >= 0){ p = P[p]; d++; };
        printf("%d, ", d);
        if(P[i] < 0){
            printf("root");
        }else if(C[i] < 0){
            printf("leaf");
        }else{
            printf("internal node");
        }
        printf(", [");
        if(C[i] >= 0){
            printf("%d", C[i]);
            p = C[i];
            while(S[p] >= 0){ printf(", %d", S[p]); p = S[p]; };
        }
        printf("]\n");
    }
    delete [] P; delete [] C; delete [] S;

    return 0;
}