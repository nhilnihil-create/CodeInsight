#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <map>

using namespace std;

#define MAX 500002

int left(int i){
    return i*2;
}
int right(int i){
    return i*2+1;
}

/*
 *  添字indexから始まる部分木がmax-ヒープになるようにする。
 *
 * */
void maxHeapify(int *heap,int index,int H){
    int l;int r=-1;
    if(left(index)<=H){
        l=left(index);
    }
    if(right(index)<=H){
        r=right(index);
    }

    int largest;
    if(l<=H&&heap[l]>heap[index]){
        largest=l;
    }else{
        largest=index;
    }

    if(r>=1&&r<=H&&heap[r]>heap[largest]){
        largest=r;
    }

    if(largest!=index){
        swap(heap[index],heap[largest]);
        maxHeapify(heap,largest,H);
    }

}

/*
 *
 * ボトムアップに、部分木をmax-ヒープにすることで全体木をmax-ヒープにする。
 *
 * */
void buildMaxHeap(int *heap,int H){
    for(int i=H/2;i>=1;i--){
        maxHeapify(heap,i,H);
    }
}

void printHeap(int *heap,int H){
    for(int i=1;i<=H;i++){
        printf(" %d",heap[i]);
    }
}

int main() {


    int heap[MAX];
    int H;scanf("%d",&H);

    for(int i=1;i<=H;i++){
        scanf("%d",&heap[i]);
    }

    buildMaxHeap(heap,H);

    printHeap(heap,H);
    
    printf("\n");

    return 0;
}
