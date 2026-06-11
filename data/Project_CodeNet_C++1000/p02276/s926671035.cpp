//
//  main.cpp
//  partition
//
//  Created by ???????????? on 2017/10/08.
//  Copyright ?? 2017 ????????????. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int p, int r){
    int x = A[r];
    int i = p - 1;
    for(int j = p; j < r; j ++){
        if(A[j] <= x){
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i+1;
}

int main(int argc, const char * argv[]) {
    int n, i;
    scanf("%d", &n);
    int A[n];
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    int ind = partition(A, 0, n-1);
    for(i = 0; i < n; i++){
        if(i) cout << " ";
        
        if(i == ind){
            cout << "["<<A[i]<<"]";
        }
        else if (i != ind){cout << A[i];}
    }
    cout << endl;
    return 0;
}