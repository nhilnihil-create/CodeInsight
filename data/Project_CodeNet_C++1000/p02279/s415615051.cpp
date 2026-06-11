#include <iostream>
#include <stdio.h>  //printf

using namespace std;

#define N_MAX 100000
#define NIL -1

struct Node{int p, l, r;};

Node T[N_MAX];

int main()
{
    int n, i, j, v, d, x, y;
    cin >> n;

    //??¨????????????
    for (i = 0; i < N_MAX; i++) {
        T[i].p = -1;
        T[i].r = T[i].l = NIL;
    }

    //??¨?????\???
    for (i = 0; i < n; i++) {
         cin >> v >> d; // value, degree

             for (j = 0; j < d; j++) {
                 cin >> x;
                 if (j == 0) {
                     T[v].l = x;
                     T[x].p = v;
                 } else {
                     T[y].r = x;
                     T[x].p = v;
                 }
                 y = x;
             }

    }

    //??¨?????????
    for (i = 0; i < n; i++) {
        v = i;
        j = 0;
        while (T[v]. p != -1) {
            v = T[v].p;
            j++;
        }
        printf("node %d: parent = %d, depth = %d, ", i, T[i].p, j);

        if (T[i].p == -1) {
            printf("root, ");
        } else if (T[i].l == NIL) {
            printf("leaf, ");
        } else {
            printf("internal node, ");
        }

        printf("[");
        if (T[i].l == NIL) {
            printf("]\n");
            continue;
        } else {
            printf("%d", T[i].l);
            v = T[i].l;
        }

        while (T[v].r != NIL) {
            printf(", %d", T[v].r);
            v = T[v].r;
        }
        printf("]\n");
    }

    return 0;
}