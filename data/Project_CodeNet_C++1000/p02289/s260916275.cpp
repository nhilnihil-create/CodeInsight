#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

#define NUM 4000000
#define NIL -1
int A[NUM];
int heap_n = 0;

void init(){
    for(int i = 0; i < NUM; i++){
        A[i] = NIL;
    }
}

void upHeapify(int num){
    if(num == 1){
        return;
    }
    
    if(A[num] > A[num / 2]){
        int tmp = A[num];
        A[num] = A[num / 2];
        A[num / 2] = tmp;
        upHeapify(num / 2);
    }
}

void downHeapify(int num){
    int m = max(A[num], max(A[num * 2], A[num * 2 + 1]));

    if(m == A[num * 2]){
        swap(A[num * 2], A[num]);
        downHeapify(num * 2);
        return;
    }
    if(m == A[num * 2 + 1]){
        swap(A[num * 2 + 1], A[num]);
        downHeapify(num * 2 + 1);
        return;
    }
}


void insert_(int num){
    A[heap_n + 1] = num;
    heap_n++;
    upHeapify(heap_n);
}

void pop_(){
    A[1] = A[heap_n];
    A[heap_n] = NIL;
    heap_n--;
    downHeapify(1);
}

int main(void){
    init();
    char buf[100];
    int num;
    
    while(1){
        scanf("%s", buf);
        if(!strcmp(buf, "end")){
            break;
        }

        if(!strcmp(buf, "insert")){
            scanf("%d", &num);
            insert_(num);
        }

        if(!strcmp(buf, "extract")){
            printf("%d\n", A[1]);
            pop_();
        }

        if(!strcmp(buf, "print")){
            for(int i = 1; i <= heap_n; i++){
                printf("%d ", A[i]);
            }
        }
    }
}

