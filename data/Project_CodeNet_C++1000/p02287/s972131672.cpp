
#include <cstdlib>
#include <iostream>
#include <stdio.h>

using namespace std;

/*
 * 
 */

#define MAX 251

void print(int *binaryHeap, int num) {
    
    for(int i = 1; i < num + 1; i++) {
        printf("node %d: key = %d, ",i, binaryHeap[i]);
        
        if(i / 2 > 0) {
            printf("parent key = %d, ", binaryHeap[i / 2]);
        }
        if(2 * i <= num) {
            printf("left key = %d, ", binaryHeap[2 * i]);
        }
        if(2 * i + 1 <= num) {
            printf("right key = %d, ", binaryHeap[2 * i + 1]);
        }
        cout << endl;
    }
}

int main(void) {
    //ifstream ifs;
    //ifs.open("./input.txt", ifstream::in);
    int num;
    //ifs >> num;
    cin >> num;
    int binaryHeap[MAX];
    for(int i = 1; i < num + 1; i++) {
        cin >> binaryHeap[i];
        
    }
    
    print(binaryHeap, num);
    
    
    return 0;
}