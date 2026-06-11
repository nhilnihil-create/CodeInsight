//
//  main.cpp
//  ALDS1_6_B
//
//  Created by ptyuan on 2018/10/29.
//  Copyright © 2018 YY. All rights reserved.
//

#include <iostream>
#include <cstdio>

int partition(int *A, int p, int r) {
    int x = A[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++) {
        if (A[j] <= x) {
            i++;
            int temp = A[j];
            A[j] = A[i];
            A[i] = temp;
        }
    }
    A[r] = A[i + 1];
    A[i + 1] = x;
    return i + 1;
}

int main(int argc, const char * argv[]) {
    int n = 0;
    int A[100000];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", A + i);
    }
 
    int p = partition(A, 0, n - 1);
    for (int i = 0; i < n; i++) {
        int indexValue = A[i];
        if (i > 0) {
            printf(" ");
        }
        if (i == p) {
            printf("[%d]", indexValue);
        } else {
            printf("%d", indexValue);
        }
    }
    printf("\n");
    return 0;
}

